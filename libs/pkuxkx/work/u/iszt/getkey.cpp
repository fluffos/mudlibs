
int getkey()
{
        char c;

        c = _getch(); //????????

        if (int( c ) == BACKSPACE) //??
                return BACKSPACE;

        if (int( c ) == ENTER) //??
                return ENTER;
        if (int( c ) >= 27 && int( c ) <= 122) //A~Z, a~z
        {
                return c;
        } 
        else
        {
                c = _getch(); //????????
                switch(c)
                {
        //              ?????????
                case 72: return UP;
                case 80: return DOWN;
                case 75: return LEFT;
                case 77: return RIGHT;
                case 71: return HOME;
                case 79: return END;
                case 73: return PGUP;
                case 81: return PGDN;
                case 27: return ESC;
                case 59: return F1;
                case 60: return F2;
                case 61: return F3;
        //      case 62: return F4;
        //      case 63: return F5;
        //      case 64: return F6;
        //      case 65: return F7;
        //      case 66: return F8;
        ///     case 'S': return DEL;
                default: return INVALID_INPUT; //??????
                }
        }
}
