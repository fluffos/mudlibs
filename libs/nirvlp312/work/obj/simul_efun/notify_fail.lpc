/* Notify fail sefun
*/
void notify_fail(mixed message)
{
    if ( !(stringp(message) && strstr(message, "@@") < 0) ) {
        efun::notify_fail(message);
        return;
    }
    efun::notify_fail(
      funcall(
        bind_lambda(#'lambda, previous_object()),
        0, ({#'process_string, message})
      )
    );
}

