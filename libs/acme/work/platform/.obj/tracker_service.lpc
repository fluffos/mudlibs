/**
 * A service for initializing and reloading tracker objects.
 * 
 * @author devo@eotl
 * @alias TrackerService
 */
#pragma no_clone

private inherit ObjectLib;

public void setup();
public object reload_tracker(string tracker);
public void load_trackers();

/**
 * Setup the TrackerService.
 */
public void setup() {
  load_trackers();
}

/**
 * Load or reload a specified tracker object.
 * 
 * @param  tracker       the path to the tracker object to load
 * @return the loaded tracker object
 */
public object reload_tracker(string tracker) {
  object result = FINDO(tracker);
  if (result) {
    result = reload_object(result);
  } else {
    result = load_object(tracker);
    result->init_tracker();
  }
  return result;
}

/**
 * Global tracker load sequence.
 */
public void load_trackers() {
  reload_tracker(FileTracker);
  reload_tracker(DomainTracker);
  reload_tracker(ProgramTracker);
  reload_tracker(ObjectTracker);
  reload_tracker(ConnectionTracker);
  reload_tracker(SessionTracker);
  reload_tracker(ZoneTracker);
}

/**
 * Constructor. Load trackers.
 */
public void create() {
  setup();
}
