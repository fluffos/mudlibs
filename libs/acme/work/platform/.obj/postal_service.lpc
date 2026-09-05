/**
 * The postal service object. It is responsible for sending messages back and
 * forth between objects. This should be the only use of efun::tell_object() in 
 * the lib.
 *
 * @author devo@eotl
 * @alias PostalService
 */
#pragma no_clone
#include <message.h>
#include <capability.h>
#include <topic.h>

private inherit MessageLib;
private inherit CapabilityLib;
private inherit JSONLib;

public void setup();
public varargs struct Message send_message(object target, string topic, 
                                           string message, mapping context, 
                                           object sender);
public varargs struct Message prompt_message(object target, string message, 
                                             mapping context, object sender);
private void message(object target, string topic, struct Message msg);
public void newline(object target);

/**
 * Setup the PostalService.
 */
public void setup() {
}

/**
 * Send a message to an object. Target must be a sensor.
 * 
 * @param  target        the object to which the message should be delivered,
 *                       must be a "sensor"
 * @param  topic         the message topic, a way to group common messages
 *                       together
 * @param  message       the message to be delivered, a string
 * @param  context       the message context, a mapping
 * @param  sender        the object doing the sending, or 0 for anonymous 
 *                       messages
 * @return a Message struct representing the sent message, or 0 if message
 *         could not be sent
 */
public varargs struct Message send_message(object target, string topic, 
                                           string message, mapping context, 
                                           object sender) {
  object logger = LoggerFactory->get_logger(THISO);

  if (!mappingp(context)) {
    context = ([ ]);
  }
  
  if (!target->is_sensor()) {
    return 0;
  }

  if (sender && (sender != previous_object())) {
    raise_error("not allowed to spoof\n");
    return 0;
  }

  mixed *args, ex;
  if (ex = catch(args = target->try_message(topic, message, context, sender); 
                 publish)) {
    logger->trace("caught exception in try_message: %O", ex);
    return 0;
  } 

  struct Message msg = target->render_message(topic, message, context, sender);
  message(target, topic, msg);
  apply(#'call_other, target, "on_message", msg, args);
  return msg;
}

/**
 * Send a prompt message to an object. Target must be interactive, but not
 * necessarily a sensor.
 * 
 * @param  target        the object to which the message should be delivered,
 *                       must be interactive
 * @param  message       the message to be delivered, a string
 * @param  context       the message context, a mapping
 * @param  sender        the object doing the sending, or 0 for anonymous 
 *                       messages
 * @return a Message struct representing the sent message, or 0 if message
 *         could not be sent
 */
public varargs struct Message prompt_message(object target, string message, 
                                             mapping context, object sender) {
  if (!interactive(target)) {
    // TODO review this, maybe do target->is_interactive() instead
    return 0;
  }  

  if (!mappingp(context)) {
    context = ([ ]);
  }

  if (sender && (sender != previous_object())) {
    raise_error("not allowed to spoof\n");
    return 0;
  }

  string topic = TOPIC_PROMPT;
  struct Message msg = target->render_message(topic, message, context, sender);
  message(target, topic, msg);
  return msg;
}

/**
 * Perform the message transmission to the client.
 * 
 * @param  target        the object to which the message should be delivered,
 *                       must be interactive
 * @param  topic         the message topic
 * @param  msg           the message to be delivered
 */
private void message(object target, string topic, struct Message msg) {
  string message = msg->message;
  if (msg->term == WebClientTerm) {
    message = ",\n" + json_encode(([
      "topic" : topic,
      "message" : msg->message,
      "context" : msg->context
    ]));
  }
  efun::tell_object(target, message);
}

/**
 * Send a newline to an object. Newline is sent raw, no additional rendering
 * is performend.
 * 
 * @param  target        the object to which the message should be delivered
 */
public void newline(object target) {
  efun::tell_object(target, "\n");
}

/**
 * Constructor.
 */
public void create() {
  setup();
}