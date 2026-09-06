/* A station of the O.E.R. */

inherit "/d/avalon/common/railway/rails";

int             trough_station, wait;
mixed          *trains;

int 
SetWait(int i)
{
    return wait = i;
}

int 
QueryWait()
{
    return wait;
}

void 
create()
{
    ::create();
    trains = ({});
    Set("IsStation",1);
}

string 
QueryDestination(int direction)
{
    int             i;
    string          destination;
    if (!previous_object()->id("train"))
	return ::QueryDestination(direction);
    if (trough_station) {	/* the station is a trough-station */
	if (sizeof(trains) && (i = member(trains, previous_object())) != -1) {	/* the train is already
											 * here? */
	    trains = trains[0..i - 1] + trains[i + 1..sizeof(trains) - 1];
	    return ::QueryDestination(direction);
	}
	 /* erase them in the train list and start */ 
	else {
	    trains += ({previous_object()});
	    call_out("start_train", QueryWait(), ({previous_object(), direction}));
	    return 0;		/* stop them and store them in the train */
	}			/* list */
    }
    if (!(destination = ::QueryDestination(direction)))
	call_out("start_train", QueryWait(), ({previous_object(), 1 - direction}));
    return destination;
}

void 
start_train(mixed train)
{
    if (!train[0])
	return;
    train[0]->SetDirection(train[1]);
    train[0]->start_train();
}
