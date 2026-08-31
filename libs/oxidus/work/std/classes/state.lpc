#ifndef __STATE_STEP__
#define __STATE_STEP__

/**
 * @typedef {class} StateStep - Represents a step in a state machine.
 *
 * @property {string} name - The label/name of this step.
 * @property {function} enter - The function to trigger to begin this state,
 * @property {function} exit - The function to trigger when this step has completed.
 * @property {int} completed - Set as 1 to note that this step has completed, default is 0 (undefined)
 *
 * A step used in a state machine. Contains functions for entering and exiting
 * a state as well as its name and a toggle for being completed or not.
 */
class StateStep {
  string name;
  function enter;
  function exit;
  int completed;
}

#endif // __STATE_STEP__
