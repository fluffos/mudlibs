/**
 * The basic unit of interaction in the game is a "message," the SensorMixin
 * provides objects the capability to "sense" those messages. Without it, any
 * output or messages an object may receive are simply regarded as noise.
 *
 * @author devo@eotl
 * @alias SensorMixin
 */
#pragma no_clone
#include <capability.h>
#include <command_giver.h>
#include <message.h>
#include <sensor.h>

private inherit JSONLib;
private inherit MessageLib;
private inherit ObjectLib;

private mapping CAPABILITIES_VAR = ([ CAP_SENSOR ]);
private mapping CMD_IMPORTS_VAR = ([ ]);

private int enabled;

public void setup();
public void teardown();
int is_sensor();
string query_terminal_type();
public mixed *try_message(string topic, string message, mapping context, 
                          object sender);
public struct Message render_message(string topic, string message, 
                                     mapping context, object sender);
public void on_message(struct Message msg);
protected void init_terminal();
protected void close_terminal();

/**
 * Setup the SensorMixin.
 */
public void setup() {
  enabled = 1;
}

/**
 * Tear down the SensorMixin.
 */
public void teardown() {
  enabled = 0;
}

/**
 * Return true to indicate this object is a sensor.
 * 
 * @return 1
 */
int is_sensor() {
  return enabled;
}

/**
 * Get the terminal type of this sensor. Returns a reasonable default at the
 * base implementation, but my be overridden by avatars to get from connection
 * info instead.
 * 
 * @return the default terminal type
 */
string query_terminal_type() {
  string connection = ConnectionTracker->query_connection(THISO);
  string result;
  if (connection) {
    result = ConnectionTracker->query_terminal(connection);
  }
  if (!result) {
    result = DEFAULT_TERMINAL_TYPE;
  }
  return result;
}

/**
 * Invoked by PostalService before a message is sent to prevent or otherwise
 * prepare the message for delivery.
 * 
 * @param  topic         the message topic
 * @param  message       the message
 * @param  context       the message context
 * @param  sender        the sending object, or for anonymous messages
 * @return extra args to be passed to on_message() after delivery
 */
public mixed *try_message(string topic, string message, mapping context, 
                          object sender) {
  return ({ });
}

/**
 * Render an incoming message. The SensorMixin's implementation of 
 * render_message() is to dispatch the actual rendering to a shared renderer 
 * object based on topic and terminal type of this sensor.
 * 
 * @param  topic         the message topic
 * @param  message       the message
 * @param  context       the message context
 * @param  sender        the sending object, or for anonymous messages
 * @return a new Message struct representing the rendered message info
 */
public struct Message render_message(string topic, string message, 
                                     mapping context, object sender) {
  object logger = LoggerFactory->get_logger(THISO);
  string term = query_terminal_type();
  struct Message result = (<Message>
    topic: topic,
    message: message,
    context: context,
    term: term
  );
  object renderer = TopicTracker->get_renderer(topic, term);
  if (renderer) {
    result->message = (renderer->render(term, topic, message, context, 
                                        sender));
  } else {
    logger->warn("No renderer found for topic %O, term %O", topic, term);
  }
  return result;
}

/**
 * This function is invoked by PostalService after a message has been rendered
 * and delivered.
 * 
 * @param  msg  the rendered message
 */
public void on_message(struct Message msg) {
  return;
}

/**
 * Call this function if the sensor has just connected to the game for the
 * first time (but preferably after terminal type has been detected). It will
 * initialize the message stream, and should not be called more than once
 * per cconnection.
 */
protected void init_terminal() {
  string terminal = query_terminal_type();
  if (terminal == WebClientTerm) {
    efun::tell_object(THISO, "[\n{ }");
  }
}

/**
 * Call this function if the sensor is about to disconnect to gracefully
 * terminate the message stream. If the connection is terminated unexpectedly
 * it is up to the client to ensure the message term is terminated correctly.
 * Once this function has been called there is no guarantee any further
 * messaging will be delivered to the client.
 */
protected void close_terminal() {
  string terminal = query_terminal_type();
  if (terminal == WebClientTerm) {
    efun::tell_object(THISO, "\n]");
  }
}

