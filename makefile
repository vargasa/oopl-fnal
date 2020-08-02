.DEFAULT_GOAL := all

all:

clean:
	cd cpp; make clean

config:
	git config -l

init:
	git init
	git remote add origin git@gitlab.com:gpdowning/oopl-fnal.git
	git add README.md
	git commit -m 'first commit'
	git push -u origin master

pull:
	make clean
	@echo
	git pull
	git status

push:
	make clean
	@echo
	git add .gitignore
	git add .gitlab-ci.yml
	git add cpp
	git add makefile
	git add notes
	git add README.md
	git add uml
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -p -r -t -u -v --delete         \
    --include ".gitignore"                 \
    --include ".gitlab-ci.yml"             \
    --include "makefile"                   \
    --exclude "*"                          \
    . gpdowning@$(OOPL):oopl/git/fnal/
	cd cpp; make sync
	@echo
	cd uml; make sync

versions:
	cd cpp; make versions
