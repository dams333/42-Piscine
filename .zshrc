export ZSH="/Users/dhubleur/.oh-my-zsh"

ZSH_THEME="agnoster"

DISABLE_UPDATE_PROMPT="true"

plugins=(git)

source $ZSH/oh-my-zsh.sh

open /sgoinfre/goinfre/Perso/aguiot--/public/RP42.app

alias zshconf="vim ~/.zshrc"
alias vimconf="vim ~/.vimrc"
alias norm="norminette -R CheckForbiddenSourceHeader"
alias normh="norminette -R CheckDefine"
alias gc42="gcc -Wall -Wextra -Werror"
alias work="cd ~/Documents/Piscine"

function fsave()
{
	local PREVPWD = $PWD
	cd ~/shell && ./save.sh
	cd $PREVPWD
}
alias forcesave="~/shell && ./save.sh && cd ~/Documents/Piscine"

function cd()
{
	builtin cd $@ && ls
}
