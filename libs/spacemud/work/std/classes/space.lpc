class star
{
   string name;
   string spectral_type;
   string colour;
   string col;
   int temperature_min;
   int temperature_max;
}

class structure
{
   string name;
   int beacon;   // Public structure that sends signals?
   int distance; // Distance in kilometer from planet, 0 meaning on. Orbit is around 400 km from planets.
   string owner;
}

class planet
{
   string name;
   string type;
   string player_name;
   string named_by_player;
   float radius; // In KM
   float mass;   // in 10^24 kg
   string col;
   float gravity; // In Gs, earth=1.
   float surface; // 10^6 km3
   int moons;
   class structure *structures;
}

class starsystem
{
   int *coordinates; // Measure in light years for starsystems.
   string name;
   string player_name;
   string named_by_player;
   class star star;
   int planets_count;
   class planet *planets;
}

class ship_info
{
   string vfile;
   string name;
   string type;
   string starsystem;
   string location;
   string docked_at;
   int long_term;
}

class docking_info
{
   string vfile;
   int docking_time;
   string who;
   string dock_name;
}

class spacestation_config
{
   float docking_fee; // crd per docking
   float storage_fee; // crd per day stored
}