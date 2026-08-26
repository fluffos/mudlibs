
#include <http.h>

#define WEBMASTER "shaydz@divided-sky.com"

private mixed title;
private mixed content;
private mixed on_load;
private string script;
private function access;

/** @ignore yes */
protected void set_title( mixed str ) { title = str; }

/** @ignore yes */
protected void set_content( mixed str ) { content = str; }

/** @ignore yes */
protected void set_script( string str ) { script = str; }

/** @ignore yes */
protected void set_on_load( mixed str ) { on_load = str; }

/** @ignore yes */
protected void set_access( function fun ) { access = fun; }

/** @ignore yes */
protected void create() {
    TO->setup();
    if( !title )
        title = mud_name();
} /* create() */

/** @ignore yes */
string the_date( int i ) {
    string ret;

    ret = ctime( i );

    return ret[4..9]+", "+ret[20..];

} /* the_date() */

/** @ignore yes */
string htmlify_no_address( string str ) {
    string pre, post;

    str = replace( str, ({"&", "&amp;", "<", "&lt;",
                          ">", "&gt;", "\n", "<br>\n"
                          }) );

    while( sscanf( str, "%s  %s", pre, post ) == 2 )
        str = pre + "&nbsp;&nbsp;" + post;

    return str;

} /*  htmlify_no_address() */

/*
 * Makes all the '<' turn into $gt; and the '>' the same.  Turn
 * http addresses into real addresses...
 */
string htmlify( string  str ) {
    string *bits;
    string start, end, extra;
    int i;

    str =  htmlify_no_address(str);

    if( strsrch( str, "http:") > 0 ) {
        bits = explode("#"+str, "http:");
        bits[0] = bits[0][1..];
        for( i = 1; i < sizeof(bits); i++ ) {
            if( sscanf( bits[i], "%s&nbsp;%s", start, end ) == 2 ||
                sscanf( bits[i], "%s %s", start, end ) == 2 ) {
                end = "&nbsp;" + end;
                if( sscanf( start, "%s<br>%s", start, extra ) == 2 )
                    end = "<br>" + extra + end;
            } else if( sscanf( bits[i], "%s<br>%s", start, end) == 2 ) {
                end = "<br>" + end;
            } else {
                start = bits[i];
                end = "";
            }
            if( start[<1] == '.') {
                start = start[0..<2];
                end = "." + end;
            }
            bits[i] = "<a target=\"_new\" href=\"http:"+start+"\">http:"+
                start+"</a>"+end;
        }
        str = implode( bits, "");
    }

    return str;

} /* htmlify() */

/** @ignore yes */
protected varargs string create_header( string name, mapping args,
                                        class http_request req ) {
    string tmp;

    if( on_load ) {
        if( functionp(on_load) ) {
            tmp = evaluate( on_load, name, args, req );
            if( tmp && tmp != "")
                tmp = " onLoad=\""+tmp+"\"";
        } else {
            tmp = " onLoad=\""+on_load+"\"";
        }
    }

    if( !tmp )
        tmp = "";

    return "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n"
           "<html><head><title>"+( functionp(title) ?
           evaluate( title, name, args, req ) : title )+"</title>\n"
           "<meta http-equiv=\"Content-Type\" content=\"text/html; "
           "charset=iso-8859-1\">\n"
           "<link rel=\"stylesheet\" href=\"/defs.css\" type=\"text/css\">\n"+
           ( script || "")+"</head>\n"
           "<body bgcolor=\"#333333\" text=\"#FFFFFF\" link=\"#CCCCCC\" "
           "vlink=\"#999999\" alink=\"#3399FF\" leftmargin=\"10\" "
           "topmargin=\"10\" marginwidth=\"10\" marginheight=\"10\""+tmp+">\n"
           "<a name=\"#top\"></a>\n";

} /* create_header() */

/** @ignore yes */
protected varargs string create_footer( string name, mapping args,
                                        class http_request req ) {
    return "<br></body></html>\n";
} /* create_footer() */

/** @ignore yes */
string font() {
    return "<font size=\"2\" face=\"Arial, Helvetica, sans-serif\">\n";
} /* query_font() */

/** @ignore yes */
string no_access() {
    return font()+"<h3>You do not have the rights to access this page.</h3>\n"
        "<p><a href=\"/secure/secure.c\">Back to the Secure Section</a>\n"
        "</p></font>";
} /* no_access() */

/** @ignore yes */
string www_request( string name, mapping args, class http_request req ) {
    if( functionp(access) && !evaluate( access, req->user ) )
        return create_header( name, args, req ) + no_access() +
           create_footer( name, args, req );

    return create_header( name, args, req ) + ( functionp(content) ?
           evaluate( content, name, args, req ) : content ) +
           create_footer( name, args, req );

} /* www_request() */

/** @ignore yes */
string webmaster() {
    return WEBMASTER;
} /* back() */

/** @ignore yes */
void dest_me() { destruct(TO); }
