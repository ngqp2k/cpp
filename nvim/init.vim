:set number
:set relativenumber
:set autoindent
:set tabstop=4
:set shiftwidth=4
:set smarttab
:set softtabstop=4
:set mouse=a

call plug#begin()

" ------------------------- Them-------------------------------

Plug 'vim-airline/vim-airline' " Status bar
Plug 'rafi/awesome-vim-colorschemes' " Retro Scheme
Plug 'ap/vim-css-color' " CSS Color Preview
Plug 'octol/vim-cpp-enhanced-highlight' " syntax highlight

" -------------------------------------------------------------

" ---------------------- Files browser ------------------------

Plug 'preservim/nerdtree' " NerdTree
Plug 'ryanoasis/vim-devicons' " Developer Icons

" -------------------------------------------------------------

" ------------------------- Code ------------------------------

Plug 'http://github.com/tpope/vim-surround' " Surrounding ysw
Plug 'https://github.com/tpope/vim-commentary' " For Commenting gcc & gc
Plug 'https://github.com/neoclide/coc.nvim'  " Auto Completion
Plug 'https://github.com/terryma/vim-multiple-cursors' " CTRL + N for multiple cursors

" -------------------------------------------------------------
"
" ------------------------- Util ------------------------------

Plug 'https://github.com/tc50cal/vim-terminal' " Vim Terminal
Plug 'https://github.com/preservim/tagbar' " Tagbar for code navigation

" -------------------------------------------------------------

"	" --> File browser
	" Plug 'preservim/nerdTree'
"	" Plug 'Xuyuanp/nerdtree-git-plugin'
"	" Plug 'ryanoasis/vim-devicons'
"	" Plug 'tiagofumo/vim-nerdtree-syntax-highlight'
call plug#end()


nmap <F8> :TagbarToggle<CR>

:set completeopt-=preview " For No Previews

:colorscheme gruvbox 


noremap <expr> <Tab> pumvisible() ? coc#_select_confirm() : "<Tab>"


nnoremap<silent> <C-J> <C-W><C-J>
nnoremap<silent> <C-K> <C-W><C-K>
nnoremap<silent> <C-L> <C-W><C-L>
nnoremap<silent> <C-H> <C-W><C-H>


" Quick open neovim config file
nnoremap<silent> <F12> :e $MYVIMRC<CR>
let nvim_settings_dir = '~/.config/nvim/plugin-settings/'
execute 'source'.nvim_settings_dir.'NERDTree_settings.vim'
execute 'source'.nvim_settings_dir.'Airline_settings.vim'
" " execute 'source'.nvim_settings_dir.'fzf_settings.vim'
" " execute 'source'.nvim_settings_dir.'coc_settings.vim'
" execute 'source'.nvim_settings_dir.'commenter_settings.vim'
" execute 'source'.nvim_settings_dir.'telescope_settings.vim'
