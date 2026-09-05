/**
 * A renderer for the login object.
 *
 * @author devo@eotl
 * @alias LoginRenderer
 */
#include <ansi.h>
#include <topic.h>

inherit DefaultRenderer;
 
private inherit RenderLib;

public string render(string term, string topic, string message, 
                     mapping context, object sender);
string render_welcome(string term, string topic, string message, 
                       mapping context, object sender);

/**
 * Render a message for a specified term and topic.
 * 
 * @param  term          the message target's terminal type
 * @param  topic         the message topic
 * @param  message       the message, a string
 * @param  context       the message context, a mapping
 * @param  sender        the message sender, or 0 for anonymous messages
 * @return the rendered message string to send to the target's terminal
 */
public string render(string term, string topic, string message, 
                     mapping context, object sender) {
  switch (topic) {
    case TOPIC_WELCOME:
      return render_welcome(term, topic, message, context, sender);
    case TOPIC_LOGIN:
      return render_default(term, topic, message, context, sender);
    default:
      return DefaultRenderer::render(term, topic, message, context, sender);
  }
  return "";
}

/**
 * Rendering the welcome screen. Inserts optional content for clearing the 
 * screen, informing the user that their terminal type couldn't be detected or
 * connection is insecure.
 * 
 * @param  term          the message target's terminal type
 * @param  topic         the message topic
 * @param  message       the message, a string
 * @param  context       the message context, a mapping
 * @param  sender        the message sender, or 0 for anonymous messages
 * @return the rendered message string to send to the target's terminal
 */
string render_welcome(string term, string topic, string message, 
                       mapping context, object sender) {
  message = sprintf("%s%s%s%s\n", 
    (context["clearScreen"] ? CLEAR_SCREEN : ""), // TODO abstract ansi
    (context["defaultTerm"] ? context["defaultTerm"] + "\n" : ""),
    (message),
    (context["insecure"] ? context["insecure"] + "\n" : "")
  );
  return message;
}
