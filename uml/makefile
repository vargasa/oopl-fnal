.DEFAULT_GOAL := all

all:

sync:
	@echo ~/examples/uml/
	@rsync -p -r -t -u -v --delete         \
    --include "Stack1.uml"                 \
    --include "Stack1.svg"                 \
    --include "Stack2.uml"                 \
    --include "Stack2.svg"                 \
    --include "Shapes1.uml"                \
    --include "Shapes1.svg"                \
    --include "Shapes2.uml"                \
    --include "Shapes2.svg"                \
    --include "Shapes3.uml"                \
    --include "Shapes3.svg"                \
    --exclude "*"                          \
    ~/examples/uml/ .
