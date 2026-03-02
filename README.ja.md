# Live CV Gate Coder

## これは何?

live coding 用の engine と vim plugin。
midi to cv を使っての moduler synth を想定した live coding tool kit.

## インストール

### 動作要件

- Neovim 0.10 以上
- lcvgcエンジン（別途インストール）
- Tree-sitterハイライトを使う場合: nvim-treesitter

### lazy.nvim (推奨)

```lua
{
  'vikke/lcvgc.nvim',
  event = { 'BufReadPre *.cvg', 'BufNewFile *.cvg' },
  opts = {
    port = 9876,
    log_path = '/tmp/lcvgc.log',
  },
}
```

### vim-plug

```vim
Plug 'vikke/lcvgc.nvim'

" init.lua または after/plugin/lcvgc.lua に記述:
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

" init.lua に記述:
" require('lcvgc').setup()
```

### Tree-sitter ハイライト（任意）

nvim-treesitter を使っている場合、以下のコマンドで cvg パーサーをインストールできます:

```vim
:TSInstall cvg
```

プラグインの `setup()` 呼び出し時にパーサー情報が自動登録されるため、追加の設定は不要です。

#### Windows での準備

`:TSInstall cvg` はパーサーのCソースをコンパイルするため、Cコンパイラが必要です。
[MSYS2](https://www.msys2.org/) + MinGW-w64 の組み合わせが最も簡単です。

1. [MSYS2](https://www.msys2.org/) をインストール
2. MSYS2 ターミナルで gcc をインストール:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
3. Windows の環境変数 PATH に `C:\msys64\mingw64\bin` を追加
4. PowerShell で動作確認:
   ```powershell
   gcc --version
   ```

### 手動インストール

```bash
git clone https://github.com/vikke/lcvgc.nvim \
  ~/.local/share/nvim/site/pack/plugins/start/lcvgc.nvim
```

## テスト環境構築

テストフレームワークに [busted](https://github.com/lunarmodules/busted) を使用しています。
LuaJIT 上で動作させるため、以下の手順でセットアップしてください。

### 前提条件

- git
- gcc (C コンパイラ)
- make

### 1. luaenv のインストール

[luaenv](https://github.com/cehoffman/luaenv) と [lua-build](https://github.com/cehoffman/lua-build) を使って Lua のバージョン管理を行います。

```bash
git clone https://github.com/cehoffman/luaenv.git ~/.luaenv
git clone https://github.com/cehoffman/lua-build.git ~/.luaenv/plugins/lua-build
```

シェルの設定ファイル (`~/.bashrc` や `~/.zshrc`) に以下を追加します:

```bash
export PATH="$HOME/.luaenv/bin:$PATH"
eval "$(luaenv init -)"
```

### 2. lua-build の修正 (LuaJIT ビルド対応)

lua-build の LuaJIT 定義ファイルには `install_package`（tarball 用）が使われていますが、
URL が git リポジトリのため、`install_git` に修正する必要があります。

```bash
# luajit-2.1-rolling の定義を修正
sed -i 's/^install_package/install_git/' \
  ~/.luaenv/plugins/lua-build/share/lua-build/luajit-2.1-rolling
```

> **注意**: 他の LuaJIT バージョン（`luajit-2.1.0-beta3` 等）も同様に修正が必要です。

### 3. LuaJIT と Lua 5.1 のインストール

```bash
luaenv install luajit-2.1-rolling
luaenv install 5.1.5
```

プロジェクトでは `.lua-version` により `luajit-2.1-rolling` が自動選択されます。

### 4. luarocks のインストール

luarocks のマニフェストファイルが LuaJIT の定数制限（65536個）を超えるため、
マニフェスト処理には PUC Lua 5.1 を使い、rock のインストール先は LuaJIT にするという
ワークアラウンドが必要です。

```bash
# luarocks のソースを取得・ビルド
cd /tmp
curl -fsSL https://luarocks.org/releases/luarocks-3.11.1.tar.gz -o luarocks.tar.gz
tar xzf luarocks.tar.gz
cd luarocks-3.11.1

# LuaJIT 環境向けに configure & install
./configure \
  --prefix="$HOME/.luaenv/versions/luajit-2.1-rolling" \
  --with-lua="$HOME/.luaenv/versions/luajit-2.1-rolling" \
  --with-lua-include="$HOME/.luaenv/versions/luajit-2.1-rolling/include/luajit-2.1"
make && make install
```

### 5. luarocks のシバン差し替え (ワークアラウンド)

LuaJIT の定数制限でマニフェストが読み込めないため、`luarocks` コマンドのシバンを
一時的に PUC Lua 5.1 に差し替えて rock をインストールします。

```bash
# シバンを PUC Lua 5.1 に変更
sed -i '1s|.*|#!/home/<user>/.luaenv/versions/5.1.5/bin/lua|' \
  ~/.luaenv/versions/luajit-2.1-rolling/bin/luarocks

# busted をインストール
luarocks install busted

# シバンを LuaJIT に戻す
sed -i '1s|.*|#!/home/<user>/.luaenv/versions/luajit-2.1-rolling/bin/luajit|' \
  ~/.luaenv/versions/luajit-2.1-rolling/bin/luarocks
```

> `<user>` は自分のユーザー名に置き換えてください。

### 6. テストの実行

```bash
luaenv rehash
busted
```

## 関連プロジェクト

lcvgc.nvim は以下のプロジェクトと連携して動作します:

- [lcvgc](https://github.com/vikke/lcvgc) — ライブコーディングエンジン本体。MIDI シーケンスの評価・再生を行うバックエンド（別途インストールが必要）
- [lcvgc_mic](https://github.com/vikke/lcvgc_mic) — マイク入力からリアルタイムにピッチを検出し、lcvgc DSL形式のノートテキストを生成するCLIツール
- [tree-sitter-cvg](https://github.com/vikke/tree-sitter-cvg) — lcvgc DSL（.cvgファイル）用の Tree-sitter 文法。`:TSInstall cvg` でインストールされるパーサーのソース

### トラブルシューティング

#### `gzip: stdin: not in gzip format` (LuaJIT ビルド時)

lua-build の定義ファイルで `install_package`（tarball用）が使われているのに、
URL が git リポジトリのためです。手順2の修正を適用してください。

#### `main function has more than 65536 constants` (luarocks 実行時)

LuaJIT の定数制限により luarocks のマニフェストが読み込めません。
手順5のシバン差し替えワークアラウンドを適用してください。
