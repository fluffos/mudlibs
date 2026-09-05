/**
 * The CodeHostController. This object provides clients access to services
 * rendered by the game's code host, one of GitHub, GitLab, or BitBucket.
 * Currently the only service supported is read-only access to pull requests.
 * It's a Rodney client, so many of the operations will be asynchronous.
 *
 * @alias CodeHostController
 */
#pragma no_clone

#ifdef EOTL
inherit "rodney_client";
#define GITSITE "bitbucket"
#else
inherit RodneyClientLib;
#define GITSITE "github"
#endif

/**
 * Initialize controller.
 */
void create() {
#ifdef EOTL
  "rodney_client"::create();
  seteuid(getuid());
#else
  RodneyClientLib::create();
#endif
}

/**
 * Asynchronously get a list of pull requests from Rodney. When the pull
 * request data is received, it will be passed to the provided callback.
 *
 * @param callback callback closure to pass response
 * @param args     optional extra args to the callback
 */
void get_pull_requests(closure callback, varargs mixed *args) {
  rodney_query(GITSITE ".pullRequests", callback, args);
  return;
}

/**
 * Asynchronously get a pull request from Rodney. When the pullrequest data
 * is received, it will be passed to the provided callback.
 *
 * @param id       numerical id of the pull request to get
 * @param callback callback closure to pass response
 * @param args     optional extra args to the callback
 */
void get_pull_request(int id, closure callback, varargs mixed *args) {
  rodney_query(GITSITE ".pullRequest." + id, callback, args);
  return;
}

/**
 * Asynchronously get a pull request from Rodney. When the pullrequest data
 * is received, it will be passed to the provided callback.
 *
 * @param id       numerical id of the pull request to get
 * @param file     either the path of the file to review, or the numerical
 *                 index of that file in the file list
 * @param callback callback closure to pass response
 * @param args     optional extra args to the callback
 */
void get_pull_request_review(int id, mixed file, closure callback,
                             varargs mixed *args) {

  rodney_query(sprintf(GITSITE ".pullRequest.%d.review." + file, id),
            callback, args);
  return;
}
