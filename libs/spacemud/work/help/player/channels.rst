Channels
========

See: `gossip <gossip.html>`_ `newbie <newbie.html>`_ `new <new.html>`_ `feelings <../player_command/feelings.html>`_ 

.. TAGS: RST

Channels are a means of commnunication with other players on the MUD.
Players may listen to a channel to take part in conversation with players
that are not even in the same room.

Two channels are provided, by default, for players: gossip and newbie.
The gossip channel is for any sort of discussion the listeners may
wish.  The newbie channel is for newbie players to ask questions and
get help when they first start playing.

Players may create and listen to additional channels as they please
by using the /new flag to the chan command (see below).
[ note: we may restrict this in the future ]

All interaction with the channels is performed with the "chan" command.
Here are some example uses of the chan command:

+-----------------------+-----------------------------------------------+
| Command               | Result                                        |
+=======================+===============================================+
| chan                  | List channels being listened to               |
+-----------------------+-----------------------------------------------+
| chan gossip           | Find out whether the 'gossip' channel is      |
|                       | being listened to                             |
+-----------------------+-----------------------------------------------+
| chan gossip /on       | Turn listening on for the 'gossip' channel    |
+-----------------------+-----------------------------------------------+
| chan gossip /off      | Stop listening to 'gossip'                    |
+-----------------------+-----------------------------------------------+
| chan gossip /list     | Find out who is listening to 'gossip'         |
+-----------------------+-----------------------------------------------+
| chan gossip /who      | Same as /list                                 |
+-----------------------+-----------------------------------------------+
| chan gossip /last     | Show the last 20 messages on the channel      |
+-----------------------+-----------------------------------------------+
| chan gossip <msg>     | Send <msg> to all listeners                   |
+-----------------------+-----------------------------------------------+
| chan gossip ;<emote>  | Perform <feeling> over the channel            |
|                       | (e.g. chan gossip ;grin)                      |
+-----------------------+-----------------------------------------------+
| chan gossip :<emote>  | Send <emote> to all listeners                 |
|                       | (e.g. chan gossip :wants a big sword!)        |
+-----------------------+-----------------------------------------------+
| chan mine /new        | Create the "mine" channel                     |
+-----------------------+-----------------------------------------------+

Of course, the 'gossip' may be replaced with any channel name you
might want to use.

Once you are listening to a channel, then you can simply use that
channel's name as a command.  For example, if you listen to the gossip
channel, then you can do:

  ``gossip ;smile``
