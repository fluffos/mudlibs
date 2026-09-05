/**
 * Utility library dealing with user prompts and input_to() and such.
 * 
 * @alias PromptLib
 */
#pragma no_clone
#include <sys/input_to.h>
#include <prompt.h>

varargs protected void prompt(object ob, mixed prompt, mapping context, 
                              closure callback, varargs mixed *args);
protected void input_prompt(object ob, mixed prompt, mapping context, 
                            closure callback, mixed *args);
public void prompt_input(string input, object ob, mixed prompt, 
                         mapping context, closure callback, mixed *args);
protected void command_prompt(object ob, mixed prompt, mapping context);
protected mixed *prompt_info(object ob);

/**
 * Set a user's prompt. This will either be the user's base command prompt, 
 * or will be a temporary prompt used to gather one-time input. For single-use
 * prompts, you must pass a callback with optional additonal arguments. If no
 * callback is provided, the user's command prompt will be set. The prompt
 * itself may either be a string or a closure returning a string. A context
 * mapping may also be provided to customized the behavior of the prompt. 
 * 
 * @param  ob            the interactive object to prompt
 * @param  prompt        the prompt string or closure
 * @param  context       the prompt context
 * @param  callback      an optional callback for single-use prompts
 * @param  args          extra args for the callback
 */
varargs protected void prompt(object ob, mixed prompt, mapping context, 
                              closure callback, varargs mixed *args) {
  if (!objectp(ob)) {
    ob = THISP;
  }
  if (!stringp(prompt) && !closurep(prompt)) {
    prompt = DEFAULT_PROMPT;
  }
  if (!mappingp(context)) { 
    context = ([ ]);
  }
  if (closurep(callback)) {
    input_prompt(ob, prompt, context, callback, args);
  } else {
    command_prompt(ob, prompt, context);
  }
  return;
}

/**
 * Set a prompt using the input_to() method.
 * 
 * @param  ob            the interactive object to prompt
 * @param  prompt        the prompt string or closure
 * @param  context       the prompt context
 * @param  callback      an optional callback for single-use prompts
 * @param  args          extra args for the callback
 */
protected void input_prompt(object ob, mixed prompt, mapping context, 
                            closure callback, mixed *args) {
  context[PROMPT_TYPE] = PROMPT_TYPE_INPUT;
  object oldp = THISP;
  set_this_player(ob);
  int flags = 0;
  flags |= INPUT_PROMPT;
  if (context[PROMPT_NO_ECHO]) {
    flags |= INPUT_NOECHO;
  }
  if (context[PROMPT_IGNORE_BANG]) {
    flags |= INPUT_IGNORE_BANG;
  }
  if (!context[PROMPT_ATTEMPT]) {
    context[PROMPT_ATTEMPT] = 1;
  } 
  closure print_prompt = lambda(0, 
    ({ #',,
       ({ #'=, 
          'msg,
          ({ #'call_other, 
             PostalService, 
             "prompt_message", 
             ob,
             ({ #'funcall, prompt, ob, context }) 
          }) 
       }),
       0
    })
  );
  input_to("prompt_input", flags, print_prompt, 
           ob, prompt, context, callback, args);
  set_this_player(oldp);
  return;
}

/**
 * The input handler for input prompts. This is a wrapper for the prompt 
 * callback passed to input_prompt(). If the callback returns non-zero, the
 * same prompt may be retried depending on the prompt context.
 * 
 * @param  input         the input string
 * @param  ob            the interactive object that was prompted
 * @param  prompt        the prompt string or closure
 * @param  context       the prompt context
 * @param  callback      an optional callback for single-use prompts
 * @param  args          extra args for the callback
 */
public void prompt_input(string input, object ob, mixed prompt, 
                         mapping context, closure callback, mixed *args) {
  if (caller_stack_depth()) {
    return;
  }

  if (stringp(context[DEFAULT_PROMPT]) && (!input || !strlen(input))) {
    input = context[DEFAULT_PROMPT];
  }

  if (context[PROMPT_NO_ECHO] && ob->is_sensor()) {
    if (ob->query_terminal_type() != WebClientTerm) {
      PostalService->newline(ob);
    }
  }

  mixed result = apply(callback, input, args);
  if (result) {
    if (context[PROMPT_ATTEMPT] <= context[PROMPT_RETRY]) {
      context[PROMPT_ATTEMPT]++;
      context[PROMPT_LAST_INPUT] = input;
      context[PROMPT_LAST_RESULT] = result;
      input_prompt(ob, prompt, context, callback, args);
    }
  }
  
  return;
}

/**
 * Set a prompt using the set_prompt() method.
 * 
 * @param  ob            the interactive object to prompt
 * @param  prompt        the prompt string or closure
 * @param  context       the prompt context
 */
protected void command_prompt(object ob, mixed prompt, mapping context) {
  context[PROMPT_TYPE] = PROMPT_TYPE_COMMAND;
  closure print_prompt = lambda(({ 'quiet }), 
    ({ #'?, 
       'quiet,
       '({ prompt, context }),
       ({ #',, ({ #'call_other, 
          PostalService, 
          "prompt_message", 
          ob,
          ({ #'funcall, prompt, ob, context }) 
       }), 0 })
    })
  );
  mixed last_prompt = set_prompt(print_prompt, ob);
  context[PROMPT_LAST_PROMPT] = last_prompt;
  return;
}

/**
 * Get information on the prompt stack. The first element of the returned array
 * will contain information on the command prompt; the remaining elements will
 * be any pending input prompts, in order of least recently prompted to most
 * recently prompted. Each element will be a sub-array containing: the prompt
 * string or closure, the prompt context, the callback and callback args. The 
 * first element will not containing a callback or extra args.
 * 
 * @param  ob            the interactive object that was prompted
 * @return the prompt stack, starting with the command prompt and ending with
 *         the most recently set input prompt
 */
protected mixed *prompt_info(object ob) {
  mixed *result = ({ });
  mixed command_prompt = set_prompt(0, ob);
  if (closurep(command_prompt)) {
    result += ({ funcall(command_prompt, 1) });
  } else {
    result += ({ ({ command_prompt, ([ ]) }) });
  }
  foreach (mixed *info : input_to_info(ob)) {
    result += ({ info[3..6] });
  }
  return result;
}
