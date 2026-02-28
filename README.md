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
  'your-user/lcvgc.nvim',
  ft = 'cvg',
  opts = {
    port = 9876,
    log_path = '/tmp/lcvgc.log',
  },
}
```

### vim-plug

```vim
Plug 'your-user/lcvgc.nvim'

" Add to init.lua or after/plugin/lcvgc.lua:
" require('lcvgc').setup()
```

### packer.nvim

```lua
use {
  'your-user/lcvgc.nvim',
  config = function()
    require('lcvgc').setup()
  end,
}
```

### mini.deps

```lua
local add = MiniDeps.add
add('your-user/lcvgc.nvim')
require('lcvgc').setup()
```

### dein.vim

```vim
call dein#add('your-user/lcvgc.nvim')

" Add to init.lua:
" require('lcvgc').setup()
```

### Manual Installation

```bash
git clone https://github.com/your-user/lcvgc.nvim \
  ~/.local/share/nvim/site/pack/plugins/start/lcvgc.nvim
```

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

### Troubleshooting

#### `gzip: stdin: not in gzip format` (During LuaJIT Build)

This occurs because the lua-build definition file uses `install_package` (for tarballs), but the URL points to a git repository. Apply the fix from step 2.

#### `main function has more than 65536 constants` (When Running luarocks)

The luarocks manifest cannot be loaded due to LuaJIT's constant limit. Apply the shebang workaround from step 5.
