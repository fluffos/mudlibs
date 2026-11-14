/def F8 = /arrow_on_off%;
/def F11 = &-1%;
/def F12 = &-0%;

/def -b'^[[11~' = /F1%;
/def -b'^[[12~' = /F2%;
/def -b'^[[13~' = /F3%;
/def -b'^[[14~' = /F4%;
/def -b'^[[15~' = /F5%;
/def -b'^[[17~' = /F6%;
/def -b'^[[18~' = /F7%;
/def -b'^[[19~' = /F8%;
/def -b'^[[20~' = /F9%;
/def -b'^[[21~' = /F10%;
/def -b'^[[23~' = /F11%;
/def -b'^[[24~' = /F12%;
/def -i -b'^[[A' = /_up
/def -i -b'^[[B' = /_down
/def -i -b'^[[C' = /_right
/def -i -b'^[[D' = /_left
/def -i -b'^[[5~' = /_PgUp
/def -i -b'^[[6~' = /_PgDown
/def -i -b'^[[^@' = /_Pos1
/def -i -b'^[[e' = /_End
/set arrow_flag=0

/def _up = /dokey_up%;
/def _down = /dokey_down%;
/def _right = /dokey_right%;
/def _left = /dokey_left%;
/def _PgUp = /DOKEY RECALLB%;
/def _PgDown = /DOKEY RECALLF%;
/def _Pos1 = /DOKEY HOME%;
/def _End = /DOKEY END

/def arrow_on_off = \
        /if (arrow_flag) \
          /arrow_off%;\
        /else \
          /arrow_on%;\
        /endif%;\
        /toggle arrow_flag

/def arrow_on = \
        /echo -abCbgred Cursor-Movement-Mode ON!%;\
        /undef _up%;\
        /undef _down%;\
        /undef _right%;\
        /undef _left%;\
        /undef _PgUp%;\
        /undef _PgDown%;\
        /undef _Pos1%;\
        /undef _End%;\
        /def _up = n%;\
        /def _down = s%;\
        /def _right = o%;\
        /def _left = w%;\
        /def _PgUp = no%;\
        /def _PgDown = so%;\
        /def _Pos1 = nw%;\
        /def _End = sw

/def arrow_off = \
        /echo -abCbgred Cursor-Movement-Mode OFF!%;\
        /undef _up%;\
        /undef _down%;\
        /undef _right%;\
        /undef _left%;\
        /undef _PgUp%;\
        /undef _PgDown%;\
        /undef _Pos1%;\
        /undef _End%; \
        /def _up = /dokey_up%;\
        /def _down = /dokey_down%;\
        /def _right = /dokey_right%;\
        /def _left = /dokey_left%;\
        /def _PgUp = /DOKEY RECALLB%;\
        /def _PgDown = /DOKEY RECALLF%;\
        /def _Pos1 = /DOKEY HOME%;\
        /def _End = /DOKEY END

