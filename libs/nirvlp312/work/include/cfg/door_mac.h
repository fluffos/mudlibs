/* doors are getting more and more comprehensive */

#ifndef DOOR_H
#define DOOR_H

#define DOOR_DEST              doors[i][0]  /* door destination (filename) */ 
#define DOOR_ID                doors[i][1]  /* door id (direction) */  
#define CLOSED_FLAG            doors[i][2]  /* door closed|open */
#define DOOR_DESC              doors[i][3]  /* door 'look at' description */
#define DOOR_LOCK              doors[i][4]  /* door lock|trap difficulty */
#define DOOR_KEY               doors[i][5]  /* door key id */
#define DOOR_TRAP              doors[i][6]  /* door trap damage */
#define TRAP_ON                doors[i][7]  /* door trap on|off */
#define SECRET_DOOR            doors[i][8]  /* secret door difficulty */
#define SECRET_DOOR_FINDERS    doors[i][9]  /* names of who have found door */
#define DOOR_NUM               doors[i][10] /* door matching number */
#define TRAP_DESC              doors[i][11] /* trap description */
#define DOOR_TRAP_MSG          doors[i][12] /* trap message */
#define DOOR_TRAP_MSG_ROOM     doors[i][13] /* trap message to room */
#define LOCKED_FLAG            doors[i][14] /* door locked|unlocked */           
#define LOCK_ID                doors[i][15] /* door lock name */
#define LOCK_DESC              doors[i][16] /* door lock description */
#define DOOR_MAC_SIZE          17                                    

#define CLOSE_NEXT_ROOM(XX) \
  call_other(DOOR_DEST,"set_door_closed",file_name(this_object()),XX,DOOR_NUM)
#define TRAP_NEXT_ROOM(XX) \
  call_other(DOOR_DEST,"set_door_trap",file_name(this_object()),XX,DOOR_NUM)
#define LOCK_NEXT_ROOM(XX) \
  call_other(DOOR_DEST,"set_door_lock",file_name(this_object()),XX,DOOR_NUM)


#define NEXT_ROOM_DISARMS() \
  call_other(DOOR_DEST,"set_disarm_attempts",disarm_attempts)
#define NEXT_ROOM_DETECTS() \
  call_other(DOOR_DEST,"set_detects_attempts",detect_attempts)
#define NEXT_ROOM_LOCKS() \
  call_other(DOOR_DEST,"set_lock_attempts",lock_attempts)

#endif /* DOOR_H */

