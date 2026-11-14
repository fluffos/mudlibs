#ifndef RESTORE_H
#define RESTORE_H


/* Amylaar, mudos, and 3.1.2 have different save_object formats */
/* This will ignore incompatible driver formats                 */

protected mixed restore_object(string file) {
  mixed ret;

  if(catch(ret = efun::restore_object(file))) {
    write("Error: Save File is incorrect Format for "+ version() 
         +" Driver.\n");
    return 0;
  }
  return ret;
}

#endif /* RESTORE_H */
