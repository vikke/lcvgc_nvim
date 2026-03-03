# Live CV Gate Coder

## What is This?

An engine and Vim plugin for live coding. A live coding toolkit designed for modular synth using MIDI to CV conversion.

## Installation

### Requirements

- Neovim 0.10 or later
- lcvgc engine (installed separately)
- For Tree-sitter highlighting: nvim-treesitter

### lazy.nvim (Recommended)

```lua
{
  'vikke/lcvgc.nvim',
  event = { 'BufReadPre *.cvg', 'BufNewFile *.cvg' },
  opts = {
    port = 9876,
    log_path = '/tmp/lcvgc.log',
    debounce = 150,  -- Delay before showing completions (ms). Default: 150
  },
}
```

### vim-plug

```vim
Plug 'vikke/lcvgc.nvim'

" Add to init.lua or after/plugin/lcvgc.lua:
" require('lcvgc').setup()
```

### packer.nvim

```lua
use {
  'vikke/lcvgc.nvim',
  config = function()
    require('lcvgc').setup()
  end,
}
```

### mini.deps

```lua
local add = MiniDeps.add
add('vikke/lcvgc.nvim')
require('lcvgc').setup()
```

### dein.vim

```vim
call dein#add('vikke/lcvgc.nvim')

" Add to init.lua:
" require('lcvgc').setup()
```

### Tree-sitter Highlighting (Optional)

If you use nvim-treesitter, you can install the cvg parser with the following command:

```vim
:TSInstall cvg
```

The parser information is automatically registered when `setup()` is called, so no additional configuration is needed.

#### Windows Setup

`:TSInstall cvg` compiles the parser from C source, so a C compiler is required.
The easiest option is [MSYS2](https://www.msys2.org/) + MinGW-w64.

1. Install [MSYS2](https://www.msys2.org/)
2. In the MSYS2 terminal, install gcc:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
3. Add `C:\msys64\mingw64\bin` to your Windows PATH environment variable
4. Verify in PowerShell:
   ```powershell
   gcc --version
   ```

### Manual Installation

```bash
git clone https://github.com/vikke/lcvgc.nvim \
  ~/.local/share/nvim/site/pack/plugins/start/lcvgc.nvim
```

## Completion Behavior

When [nvim-cmp](https://github.com/hrsh7th/nvim-cmp) is installed, completions are automatically integrated as nvim-cmp custom sources.

- **LSP keyword completion**: Provided via the `nvim_lsp` source from the LSP server based on context
- **MIDI port name completion**: Provided via the `lcvgc` custom source with port names fetched from the engine

### Confirmation Behavior

In CVG files, the following behavior is applied to prevent accidental completion confirmation:

- Completion candidates are **not auto-selected** (`preselect = None`)
- `Enter` only confirms a candidate **when explicitly selected via `C-n` / `C-p`**
- Pressing `Enter` without selecting a candidate inserts a normal newline

When nvim-cmp is not installed, fallback completion via `vim.fn.complete()` is used.

### Configuration Options

| Option | Default | Description |
|--------|---------|-------------|
| `debounce` | `150` | Delay before showing completions (milliseconds) |

## Setting Up the Test Environment

We use [busted](https://github.com/lunarmodules/busted) as our testing framework. Follow the steps below to set up the environment to run on LuaJIT.

### Prerequisites

- git
- gcc (C compiler)
- make

### 1. Installing luaenv

We use [luaenv](https://github.com/cehoffman/luaenv) and [lua-build](https://github.com/cehoffman/lua-build) for Lua version management.

```bash
git clone https://github.com/cehoffman/luaenv.git ~/.luaenv
git clone https://github.com/cehoffman/lua-build.git ~/.luaenv/plugins/lua-build
```

Add the following to your shell configuration file (`~/.bashrc` or `~/.zshrc`):

```bash
export PATH="$HOME/.luaenv/bin:$PATH"
eval "$(luaenv init -)"
```

### 2. Patching lua-build (LuaJIT Build Support)

The LuaJIT definition file in lua-build uses `install_package` (for tarballs), but since the URL points to a git repository, you need to change it to `install_git`.

```bash
# Fix the luajit-2.1-rolling definition
sed -i 's/^install_package/install_git/' \
  ~/.luaenv/plugins/lua-build/share/lua-build/luajit-2.1-rolling
```

> **Note**: Other LuaJIT versions (such as `luajit-2.1.0-beta3`) require the same fix.

### 3. Installing LuaJIT and Lua 5.1

```bash
luaenv install luajit-2.1-rolling
luaenv install 5.1.5
```

The project automatically selects `luajit-2.1-rolling` via the `.lua-version` file.

### 4. Installing luarocks

The luarocks manifest file exceeds LuaJIT's constant limit (65536), so we need a workaround: use PUC Lua 5.1 for manifest processing while installing rocks to LuaJIT.

```bash
# Get and build luarocks source
cd /tmp
curl -fsSL https://luarocks.org/releases/luarocks-3.11.1.tar.gz -o luarocks.tar.gz
tar xzf luarocks.tar.gz
cd luarocks-3.11.1

# Configure and install for LuaJIT environment
./configure \
  --prefix="$HOME/.luaenv/versions/luajit-2.1-rolling" \
  --with-lua="$HOME/.luaenv/versions/luajit-2.1-rolling" \
  --with-lua-include="$HOME/.luaenv/versions/luajit-2.1-rolling/include/luajit-2.1"
make && make install
```

### 5. Changing the luarocks Shebang (Workaround)

Due to LuaJIT's constant limit, the manifest cannot be loaded. Temporarily change the `luarocks` command shebang to PUC Lua 5.1 to install rocks.

```bash
# Change shebang to PUC Lua 5.1
sed -i '1s|.*|#!/home/<user>/.luaenv/versions/5.1.5/bin/lua|' \
  ~/.luaenv/versions/luajit-2.1-rolling/bin/luarocks

# Install busted
luarocks install busted

# Change shebang back to LuaJIT
sed -i '1s|.*|#!/home/<user>/.luaenv/versions/luajit-2.1-rolling/bin/luajit|' \
  ~/.luaenv/versions/luajit-2.1-rolling/bin/luarocks
```

> Replace `<user>` with your actual username.

### 6. Running Tests

```bash
luaenv rehash
busted
```

## Related Projects

lcvgc.nvim works in conjunction with the following projects:

- [lcvgc](https://github.com/vikke/lcvgc) — The live coding engine itself. A backend that evaluates and plays back MIDI sequences (must be installed separately)
- [lcvgc_mic](https://github.com/vikke/lcvgc_mic) — A CLI tool that detects pitch in real time from microphone input and generates note text in lcvgc DSL format
- [tree-sitter-cvg](https://github.com/vikke/tree-sitter-cvg) — A Tree-sitter grammar for the lcvgc DSL (.cvg files). The source for the parser installed via `:TSInstall cvg`

### Troubleshooting

#### `gzip: stdin: not in gzip format` (During LuaJIT Build)

This occurs because the lua-build definition file uses `install_package` (for tarballs), but the URL points to a git repository. Apply the fix from step 2.

#### `main function has more than 65536 constants` (When Running luarocks)

The luarocks manifest cannot be loaded due to LuaJIT's constant limit. Apply the shebang workaround from step 5.
