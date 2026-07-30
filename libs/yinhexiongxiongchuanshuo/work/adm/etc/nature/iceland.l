#
#  The definition of day phase
#  Format:
#	length		length of the phase in seconds
#	time_msg	msg sent to outdoors user at phase starts
#	desc_msg	desc looked during the period before next phase
#	event_fun	the function is called in NATURE_D at the phase starts
#
#  Phase starts at 0:00 every day
#
#  Note the length of a phase is in minutes of a day.
#

# The two lines defines the data format in 2 lines as
#
#  field1:field2:field3....
#  format1:format2:format3....
#

length:time_msg:desc_msg:event_fun
%d:%s:%s:%s

# The following lines are data, each non-blank line will fill in each field
# in each record sequently.

600
已经是午夜了。
满天繁星, 四周一片灰蒙蒙的。
event_dawn

120
天亮了。
天空中飘著细细的雪花。
event_sunrise

180
已经是正午了。
天空中飘著细细的雪花。
event_noon

120
天慢慢地暗了下来。
四周暗了下来。
event_evening

120
夜晚降临了。
夜幕笼罩著大地
event_night

300
已经是午夜了。
夜幕低垂，满天繁星
event_midnight

