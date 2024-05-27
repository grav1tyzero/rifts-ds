inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("South West Corner");
   set_long("A hallway leading to the North Landing. Omega Ship services seems to be west of here.");
   set_exits((["north":"sw_ship_bay2", "east":"sw_ship_bay3", ]));
   // set_objects(([""]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
}
