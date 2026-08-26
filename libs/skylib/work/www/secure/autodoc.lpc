#include <http.h>
#include <autodoc.h>

/** @ignore yes */
string www_request( string str, mapping args, class http_request req ) {
    if( !creatorp(req->user) )
        return "Sorry, you shouldn't be here.";

    if( args["file"] )
        return AUTODOC_HTML->create_html_docs( args["file"] );

    return "<hr><form action=\"autodoc.c\" METHOD=GET>"
           "<b>File:</b> <input type=\"text\" name=\"file\" size=62><p>"
           "<p>"
           "<input type=\"submit\" value=\"Get docs\">"
           "<input type=\"reset\" value=\"Reset\">"
           "</form><br>";

} /* www_request() */
