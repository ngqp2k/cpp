syntax enable
syntax on
au GUIEnter * simalt ~x

set number
set ts=4 
set sw=4 
set si 
set cb=unnamed
set hls
set guifont=Fira_Code:h13:cANSI:qDRAFT
set autoread
set autowrite
set backspace=indent,eol,start
set guioptions=
set belloff=all
set mouse=a
set splitbelow
set splitright
set showcmd
set showmode
set encoding=utf-8
cd e:\cpp

nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

"---------------c++--------------------
autocmd filetype cpp nnoremap <F5> :w <bar> !g++ -o %:r %<CR>
autocmd filetype cpp nnoremap <F9> :!%:r<CR>

"---------------Comment----------------
map <C-b> <leader>c<Space>

call plug#begin('~/.vim/plugged')
	Plug 'scrooloose/nerdtree'
	Plug 'preservim/nerdcommenter'
	Plug 'kien/ctrlp.vim'
	Plug 'altercation/vim-colors-solarized'
	Plug 'sonph/onehalf', { 'rtp': 'vim' }
call plug#end()

nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>
let NERDTreeIgnore = ['\.exe$']
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() |
    \ quit | endif


"----------------NERD Commenter------------------
let g:NERDCreateDefaultMappings = 1
let g:NERDSpaceDelims = 1
let g:NERDCompactSexyComs = 1
let g:NERDDefaultAlign = 'left'
let g:NERDAltDelims_java = 1
let g:NERDCustomDelimiters = { 'c': { 'left': '/**','right': '*/' } }
let g:NERDCommentEmptyLines = 1
let g:NERDTrimTrailingWhitespace = 1
let g:NERDToggleCheckAllLines = 1"

"----------------Autoload------------------
autocmd BufNewFile *.cpp 0r ~/vim/skeleton.cpp

colorscheme default

if has("gui_running")
	colorscheme onehalflight
	let g:solarized_contrast='normal'
	let g:solarized_visibility='normal'
endif


" ----------Bind-----------
nnoremap <silent><c-s> :<c-u>update<CR>
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}
