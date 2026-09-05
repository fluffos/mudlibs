#ifndef _sys_jobs_h
#define _sys_jobs_h

#define JOB_SERVER "/etc/jobs"  // This is the job scheduler
#define J_FINISHED "job_finished"  // Field to be inserted with a 'true'
                                   // value to mark this job as finished for
                                   // the job server
#define J_PRIVILEGE "job_privilege" // This field contains the privilege for
                                    // the job
#define J_OUTPUT "job_output"       // This field either contains 1 for
                                    // output to screen or a filename to write
                                    // the results to
#define J_RESULT "job_result"       // This field contains the result the job
                                    // produced up to now (should they be
                                    // written to screen at the finishing of
                                    // the job
#define J_SIGNATURE "job_signature" // If output to screen, this is sent as
                                    // short info to the viewer
#define J_NUMBER "job_number"       // The number of the job
#define J_HANDLER "job_handler"     // The object where the function which
                                    // should do the job will be found
#define J_FUNCTION "job_function"   // The function to be called to do the
                                    // job (or at least a part of it at the
                                    // time)

// Defines for the job-type frep
#define GREP_FILES "grep_files"
#define GREP_EXPRESSION "grep_expression"

#endif  // _sys_jobs_h
