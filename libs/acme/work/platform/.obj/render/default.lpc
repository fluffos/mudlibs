/**
 * The default renderer.
 *
 * @author devo@eotl
 * @alias DefaultRenderer
 */ 
private inherit RenderLib;

public string render(string term, string topic, string message, 
                     mapping context, object sender);
string render_default(string term, string topic, string message, 
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
  return render_default(term, topic, message, context, sender);
}

/**
 * Default rendering. Uses JSON for GUI client and unaltered message string for 
 * everything else.
 * 
 * @param  term          the message target's terminal type
 * @param  topic         the message topic
 * @param  message       the message, a string
 * @param  context       the message context, a mapping
 * @param  sender        the message sender, or 0 for anonymous messages
 * @return the rendered message string to send to the target's terminal
 */
string render_default(string term, string topic, string message, 
                      mapping context, object sender) {
  return message;
}
