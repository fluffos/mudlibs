#ifndef __LOGMONEY_H__
#define __LOGMONEY_H__

void log( string s )
{
    log_file("static/money", sprintf("%s %s %d %O %s\n",
                ctime(time())[4..15],
                name(),
                query_amount(),
                this_player(), s ) );
}

#endif //..

