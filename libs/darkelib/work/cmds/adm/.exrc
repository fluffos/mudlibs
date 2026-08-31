set notimeout report=0 warn sm sw=2 ts=8 ai magic

"set wm=5

set shell=/bin/sh

"

" Comment out the current line with a C-style comment

" map \c 0i/**/ /*A */

map \c 0i/* A /* JFS */

map \C 0i/* A */ /* JFS */

map \m 0i/* A /* Sky */

"

" I hate tabs!!!

" Ctrl-X <Tab> Expands all tabs in the document to equivalent spaces

" Map the tab key to skip over a word "

" Remaps tab to space over by shift width.

map 	 1G!Gexpand

map 	 W

"map! 	 

"

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Wrap the current paragraph from the current line on.

map w !}fmt -76

"

" Turn on autowrap (wrap-margin) for when I want it (for mailing, etc)

map \w :set wm=5

"

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Spelling macros:  the first must be used on machines                        "

" that don't have ispell.  Assumes the file has already been named!           "

"map +  :w! /tmp/spl

1GO:r !spell /tmp/spl

o==SP?==SP?==ms1Gdd^

map \s :w!

:!ispell %



:e %

"

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Map \| to print out the current column number on the line below the cursor "

" This is compilcated!, I keep it comented out on purpose.

"map \| :set nosm

mx:t.

`xjaxDx!!wc -c|sed 's/ //g'|awk '{printf("\%"$1"s\%d\n","^",$1)}'

k

"

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" I want to use \W to append my ~/.sig/work and \P for ~/.sig/personal

" \A is for ~/.sig/admin

" \<space> will wipe out the phone number

map \W Go



:r $HOME/.sig/work

Gf(

map \A Go



:r $HOME/.sig/admin

G3kf(

map \P Go



:r $HOME/.sig/personal

Gf(

map \  16r 

"

""""""""""""""""""""""""""""""""""""""""""""

" Capitalization and Lowercase: whole line "

map _C :s/^.*$/\U&

map _L :s/^.*$/\L&/g

"

"""""

" PGP macros: E)ncrypt, S)ign, D)ecrypt, V)iew   (and a few others...)

map e :,$!pgp -feat 2>/dev/tty



map E :,$!pgp -feast 2>/dev/tty



map t :,$!pgp -feat mikej rjsparks ckent 2>/dev/tty



map T :,$!pgp -feast mikej rjsparks ckent 2>/dev/tty



map s :,$!pgp -fast +clear 2>/dev/tty



map d :/^-----BEG/,/^-----END/!pgp -f 2>/dev/tty||sleep 4



map v :,/^-----END/w !pgp -m

map k :r !pgp -fkx $USER



map r :/^> -----BEG/,/^> -----END/s/^..//

:/^-----BEG/,/^-----END/!pgp -f 2>/dev/tty||sleep 4

:%s/^/> /



"

" Execute current line

map x "ayy@a

map X "add@a

"

""""""""""""""""""""""""""""""

" Re-map the arrow keys to send an escape, then the appropriate movement key

map! OD h

map! OC l

map! OA k

map! OB j

