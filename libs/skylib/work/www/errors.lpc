
inherit WWW_BASE;

#define __HTTP_NO_VARIABLES__

#include <http.h>

/** @ignore yes */
string handle_error( class http_request req ) {
    string ret, status;

    switch( req->status ) {
      case MOVED_PERMANENTLY:
      case MOVED_TEMP:
        ret = sprintf("The document has moved <a href=\"%s\">here</a>.\n",
              HTTP_H->escape_html(req->location) );
      break;
      case BAD_CMD:
        ret = "Your browser sent a request that this server could not "
              "understand.\n";
      break;
      case AUTH_REQUIRED:
        ret = "This server could not verify that you are authorized to "
              "access the document you requested.  Either you supplied the "
              "wrong credentials (e.g., bad password), or your browser "
              "doesn't understand how to supply the credentials required.\n";
      break;
      case ACCESS_DENIED:
        ret = sprintf("You don't have permission to access %s on this "
              "server.</p>\n"
              "<p>This is either because you do not have the correct user "
              "permissions or because your site has been <b>temporarily</b> "
              "locked out due to excessive login failures.</p>\n"
              "<p>If you believe it is the latter wait 15 minutes and then "
              "try again.\n", HTTP_H->escape_html(req->uri) );
      break;
      case NOT_FOUND:
        ret = sprintf("The requested URL %s was not found on this server.\n",
              HTTP_H->escape_html(req->uri));
      break;
      case NOT_ALLOWED:
        ret = sprintf("The requested method %s is not allowed for the URL %s.\n",
              HTTP_H->escape_html(req->method), HTTP_H->escape_html(req->uri) );
      break;
      case TIME_OUT:
        ret = "Please, I don't have all day. Goodbye.\n";
      break;
      case LENGTH_REQUIRED:
        ret = sprintf("A request of the requested method %s requires a valid "
              "Content-length.\n", HTTP_H->escape_html(req->method) );
      break;
      case PRECONDITION_FAILED:
        ret = sprintf("The precondition on the request for the URL %s "
              "evaluated to false.\n", HTTP_H->escape_html(req->uri) );
      break;
      case NOT_IMPLEMENTED:
        ret = sprintf("%s to %s not supported.\n",
             HTTP_H->escape_html(req->method), HTTP_H->escape_html(req->uri) );
      break;
      default:
        ret = "This is the end of the line. The tomatoes have finally "
              "expired.\n";
    }

    status = (string)HTTP_H->query_status_line(req->status);

    set_title( status );

    return sprintf("%s%s<H3>%s</H3>\n<p>%s</p><p>"
        "<a href=\"http://%s/\" target=\"_top\">Back to %s Main Page</a></p>%s",
        create_header(), font(), status[4..], ret, req->hostname, mud_name(),
        create_footer() );

} /* handle_error() */
