/**
 * A service object to track changes to files.
 *
 * @alias FileTracker
 */
#pragma no_clone

// ([ regexp : ({ callbacks, ... }) ])
private mapping subscribers;

public void setup();
public int subscribe(string regexp, closure callback);
public void write_signal(string file, string func);

/**
 * Setup the FileTracker.
 */
public void setup() {
  subscribers = ([ ]);
}

/**
 * Allows objects to subscribe to file write events.
 * 
 * @param  regexp        a regular expression to match file paths against
 * @param  callback      a callback to run when a match write is triggered
 * @return 0 for failure, 1 for success
 */
public int subscribe(string regexp, closure callback) {
  if (!member(subscribers, regexp)) {
    subscribers[regexp] = ({ });
  }
  subscribers[regexp] += ({ callback });
  return 1;
}

/**
 * Called by the master object when a file write occurs.
 * 
 * @param  file          the filename being written
 * @param  func          the write operation (see valid_write())
 */
public void write_signal(string file, string func) {
  object logger = LoggerFactory->get_logger(THISO);
  if (object_name(previous_object()) == MasterObject) {
      string *f = ({ file });
      foreach (string regexp, closure *callbacks : subscribers) {
        if (sizeof(regexp(f, regexp))) {
          foreach (closure callback : callbacks) {
            funcall(callback, file, func);
          }
        }
      }
  } else {
    logger->info("unauthorized object %O invoking write_signal",
                 previous_object());
  }
  return;
}

/**
 * Constructor.
 */
public void create() {
  setup();
}

