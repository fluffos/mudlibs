#define DEBUG
/*******************************************************************************	jobs.c a job scheduler written by Ugh for Tubmud in Feb-1994
*******************************************************************************/

#include <kernel.h>
inherit ACCESS;

#include <jobs.h>
#include <wizlevels.h>

private string *job_users = ({}); /* a queue for different users which
					serves the pupose, that every
					user is served as often as all others */
private mapping job_queue;	/* a mapping which contains for every user
					in the job_users-queue */
private int actual_user;	/* a number to point out, who the next
					lagging job_user will be */
private int job_number = 1;	/* and a job-number distinguish the jobs
					from one another (we don't want the
					whole bunch removed together, do we?) 
					to be inserted while adding a job
					and incremented afterwards, so we
					don't get any doubles */
private void remove_first_job (string user);
				/* to remove finished or too_long_evaluation-
					jobs of this user */
private string error;		/* if an error occured in do_job () */
private int done;		/* if the last job was finished */
private int do_job ();			/* if there are any jobs, this function
					does a part of one, and, if this
					finished it, removes it from the
					job_queue of its user, removing
					the user as well from the queue in
					the case that it was their last job */
int add_job (mapping job, object user);	
		    /* this function gets called by external objects, trying
			to get their jobs into the job_queue of the user.
			However: privileges of this user are checked and the
			job should contain several fields:
			J_HANDLER: the object in which the function in 
			J_FUNCTION resides in, which will be called upon
			    evaluation of the job with the job itself as
			    argument,
			J_OUTPUT: which can either be 1 (for output to screen)
			    or a filename for writing the results (which
			    will later fill the field
			J_SIGNATURE: should contain a very short description
			    (like a file-name) if th output is to screen.
			J_RESULT, which needn't be in there from the
			    beginning). Your handler should also set the field
			J_FINISHED to a true value, so do_job() will know
			    when to discard it and look for the next.
			    It also can contain a message, which will be
			    told to the user, if the output should be the
			    screen.
			J_NUMBER is inserted in this function, as well,
			    marking the job with its special number, 
			    which additionally is returned */ 

void
sustain_heart_beat ()	/* this function starts or stops the heart_beat, or
				(as its name already suggests) sustains it
				in case that an error (which stopped the
				heart_beat) occured */
{
    if (sizeof (job_users)) set_heart_beat (1);
    else set_heart_beat (0);
    call_out ("sustain_heart_beat", 10);
}

void
reset (status arg)	/* let's initialize */
{
    if (arg) return;
    if (clonep (this_object ())) return destruct (this_object ());
    job_queue = ([]);
    actual_user = -1;
    set_privilege (1);
    sustain_heart_beat ();
}

status
query_prevent_shadow ()
{
  return 1;
}

status
prevent_move ()
{
	return 1;
}

void
heart_beat ()			/* let's do one job or another regularily
					with every heartbeat */
{
    mixed user;
    if (! sizeof (job_users)) return;
    if (actual_user > -1) user = job_users[actual_user];
    if (error || done) remove_first_job (user);
    if (error && user)
    {
      user = find_player (user);
      if (user) efun::tell_object (user, "ERROR in your job: "+error+"\n");
    }
    error = done = 0;
    actual_user = (sizeof (job_users) ? 
		   (actual_user + 1) % sizeof (job_users) :
		   -1);
		/* we take the next user BEFORE evaluating the next job, 
			so, if there has occured an error in the last job,
			a job from another user is taken nevertheless */
    error = catch (done = do_job ());
}

private void
remove_first_job (string user)
{
    if (!user || member(job_users, user) < 0)
      return;
    if (!sizeof (job_queue[user] = job_queue[user][1..])) {
	    job_queue = m_delete (job_queue, user);
	    job_users -= ({ user });
	    actual_user--;
    }
}

int
add_job (mapping job, mixed priv)
{
    string user_name;
    int i;
    mapping *queue;
    if (!check_privilege (priv)) return 0;
    job[J_PRIVILEGE] = priv;		/* we need it, so we can't cause
						too much mischief afterwards */
    job[J_NUMBER] = job_number++;	/* next one, please */
    user_name = this_player()->query_real_name();
    if (member(job_users, user_name) < 0) /* not in the queue, yet */
    {
	job_users += ({ user_name });		/* now they are */
	job_queue[user_name] = ({ job });
    }
    else if (job[J_OUTPUT] == 1)	    /* output to screen has a higher */
    {						/* priority than to files */
    	for (i = 0, queue = job_queue[user_name]; 
	      i < sizeof (queue) && queue[i][J_OUTPUT] == 1;
	      i++);
	job_queue[user_name] = queue[0..i-1] + ({ job }) + queue[i..];
    }
    else job_queue[user_name] += ({ job });
    set_heart_beat(1);
    return job[J_NUMBER];
}

private int
do_job ()					/* ok, let's do it */
{
    string user;
    mixed priv, output;
    mapping job;
    int number;
    object user_ob;
    if (!sizeof (job_users)) return 0;	/* no jobs waiting for us ? */
    user = job_users[actual_user];		/* get the next user */
    job = job_queue[user][0];			/* and their next job */
    priv = job[J_PRIVILEGE];			/* these three have to be */
    number = job[J_NUMBER];			/* stable, so they are saved */
    output = job[J_OUTPUT];			/* and restored afterwards */
    if (closurep (job[J_FUNCTION]))
	unguarded (priv, #'funcall, ({ job[J_FUNCTION], job }));
    else unguarded (priv, #'call_other, 
			({ job[J_HANDLER], job[J_FUNCTION], job }));
    job[J_PRIVILEGE] = priv;			/* restore the important */
    job[J_NUMBER] = number;			/* facts (at least to this */
    job[J_OUTPUT] = output;			/* scheduler) about this job */
    if (job[J_OUTPUT] != 1 && job[J_RESULT])	/* if there is no result, we
						needn't bother the driver */
	unguarded (job[J_PRIVILEGE], 		/* write the results */
		    #'write_file, ({ job[J_OUTPUT], job[J_RESULT] }));
    if (job[J_FINISHED]) 	/* remove the job if it is finished */
    {				/* and write the results if the output
				was the screen and the user is still there */
	user_ob = find_player (user);
	if (stringp (job[J_FINISHED])) 
	    efun::tell_object (user_ob, job[J_FINISHED]);
	if (job[J_OUTPUT] == 1 && job[J_RESULT])
	    user_ob->view_text (job[J_RESULT], job[J_SIGNATURE]);
	return 1;
    }
}

mapping
query_job_queue ()
{
    return copy (job_queue);
}

varargs void remove_jobs (int *number, string user) {
  int i, j;
  string *users;
  mapping *queue;
  if (this_player()->query_level() < WL_ELDER &&
	    this_player()->query_real_name() != user)
    return;
  if (user)
    users = ({ user });
  else
    users = job_users;
  for (i = 0; i < sizeof (users); i++)
	  for (j = 0, queue = job_queue[users[i]]; j < sizeof (queue); j++)
	    if (member(number, queue[j][J_NUMBER]) > -1) {
		    number -= ({queue[j][J_NUMBER]}); /* we needn't look out
				                                     for it anymore */
        if (!sizeof (job_queue[users[i]] = queue[0..j-1]+queue[j+1..])) {
		      job_queue = m_delete (job_queue, users[i]);
          if (!sizeof (job_users -= ({ users[i] }))) 
            set_heart_beat (0);
        }
      if (!sizeof(number))
         return;
	    }
}

