#pragma once

struct s_data_array
{
	char name[32];
	__int16 size;
	__int16 maximum_count;
	__int32 __unknown24;
	__int32 signature;
	__int16 __unknown2C;
	__int16 __unknown2E;
	__int32 __unknown30;
	__int32 offset_to_data;
};


template<typename t_type>
class c_data_array_base
{
public:
	char m_Name[32];
	size_t m_Size;
	unsigned int m_Signature;
	int m_MaximumCount;

private:
	char __unknown30[8];

public:
	class c_allocation_interface *m_pAllocation;
	int m_NextIndex;
	int m_FirstUnallocated;
	int m_ActualCount;
	unsigned __int16 m_NextIdentifier;
	unsigned __int16 m_IsolatedNextIdentifier;
	t_type *m_pData;
	unsigned int *m_InUseBitVector;
	int m_OffsetToData;
	int m_OffsetToBitVector;

private:
	char __unknown68[8];
};

template<typename t_type, size_t k_count>
class c_data_array : public c_data_array_base<t_type>
{
private:
	t_type m_Data[k_count];
};


struct s_lock_hierarchy_nodes
{
	char __unknown0[0x90];
};
typedef c_data_array<s_lock_hierarchy_nodes, 128> c_lock_hierarchy_nodes_data_array;
struct s_lock_hierarchy_links
{
	char __unknown0[0x14];
};
typedef c_data_array<s_lock_hierarchy_links, 1024> c_lock_hierarchy_links_data_array;
struct s_campaigns
{
	char __unknown0[0x288];
};
typedef c_data_array<s_campaigns, 4> c_campaigns_data_array;
struct s_campaign_levels
{
	char __unknown0[0x46C];
};
typedef c_data_array<s_campaign_levels, 64> c_campaign_levels_data_array;
struct s_campaign_insertions
{
	char __unknown0[0x1514];
};
typedef c_data_array<s_campaign_insertions, 64> c_campaign_insertions_data_array;
struct s_multiplayer_levels
{
	char __unknown0[0x46C];
};
typedef c_data_array<s_multiplayer_levels, 50> c_multiplayer_levels_data_array;
struct s_firefight_levels
{
	char __unknown0[0x46C];
};
typedef c_data_array<s_firefight_levels, 64> c_firefight_levels_data_array;
struct s_xbox_sound
{
	char __unknown0[0x40];
};
typedef c_data_array<s_xbox_sound, 512> c_xbox_sound_data_array;
struct s_xbox_sound_cache
{
	char __unknown0[0x18];
};
typedef c_data_array<s_xbox_sound_cache, 512> c_xbox_sound_cache_data_array;
struct s_sound_tracker
{
	char __unknown0[0x48];
};
typedef c_data_array<s_sound_tracker, 384> c_sound_tracker_data_array;
struct s_predicted_data
{
	char __unknown0[0x8];
};
typedef c_data_array<s_predicted_data, 200> c_predicted_data_data_array;
struct s_havok_components
{
	char __unknown0[0xC0];
};
typedef c_data_array<s_havok_components, 1500> c_havok_components_data_array;
struct s_havok_contact_points
{
	char __unknown0[0x50];
};
typedef c_data_array<s_havok_contact_points, 1024> c_havok_contact_points_data_array;
struct s_decal_cache
{
	char __unknown0[0x18];
};
typedef c_data_array<s_decal_cache, 2048> c_decal_cache_data_array;
struct s_tag_resource_cache
{
	char __unknown0[0x18];
};
typedef c_data_array<s_tag_resource_cache, -1> c_tag_resource_cache_data_array;
struct s_tag_resource_lruv_reverse_mapping
{
	char __unknown0[0x10];
};
typedef c_data_array<s_tag_resource_lruv_reverse_mapping, -1> c_tag_resource_lruv_reverse_mapping_data_array;
struct s_dynamic_render_targets
{
	char __unknown0[0x1C];
};
typedef c_data_array<s_dynamic_render_targets, 6> c_dynamic_render_targets_data_array;
struct s_simulation_view
{
	char __unknown0[0x118];
};
typedef c_data_array<s_simulation_view, 16> c_simulation_view_data_array;
struct s_simulation_distributed_view
{
	char __unknown0[0x120F8];
};
typedef c_data_array<s_simulation_distributed_view, 16> c_simulation_distributed_view_data_array;



struct s_object
{
	char __unknown0[16];
	void *definition;
};
static_assert(sizeof(s_object) == 0x18, "sizeof(s_object) != 0x18");

struct s_actor
{
	char __unknown0[0xCF0];
};
static_assert(sizeof(s_actor) == 0xCF0, "sizeof(s_actor) != 0xCF0");

struct s_players
{
	char __unknown0[0x558];
};
static_assert(sizeof(s_players) == 0x558, "sizeof(s_players) != 0x558");

struct s_game_engine_globals
{
	char __unknown0[0x8030];
};
static_assert(sizeof(s_game_engine_globals) == 0x8030, "sizeof(s_game_engine_globals) != 0x8030");

struct s_ai_globals
{
	char __unknown0[0x7D8];
};
static_assert(sizeof(s_ai_globals) == 0x7D8, "sizeof(s_ai_globals) != 0x7D8");

struct s_prop_reference
{
	char __unknown0[0x40];
};
static_assert(sizeof(s_prop_reference) == 0x40, "sizeof(s_prop_reference) != 0x40");

struct s_deterministic_hs_thread
{
	char __unknown0[0x52C];
};
static_assert(sizeof(s_deterministic_hs_thread) == 0x52C, "sizeof(s_deterministic_hs_thread) != 0x52C");

struct s_squad
{
	char __unknown0[0xEC];
};
static_assert(sizeof(s_squad) == 0xEC, "sizeof(s_squad) != 0xEC");

enum e_scenario_type : __int32
{
	_scenario_type_none = 0,
	_scenario_type_campaign,
	_scenario_type_multiplayer,
	_scenario_type_mainmenu,
	_scenario_type_shared,
	_scenario_type_shared_campaign,
	_scenario_type_unused5,
	_scenario_type_unused6,

	k_number_of_scenario_types
};
struct s_player_configuration
{
	char __unknown0[0xB8];
};
static_assert(sizeof(s_player_configuration) == 0xB8, "sizeof(s_player_configuration) != 0xB8");
struct s_player_options
{
	char __unknown0[0x50];
	s_player_configuration player_configuration;
};
static_assert(sizeof(s_player_options) == 0x108, "sizeof(s_player_options) != 0x108");
struct s_game_options
{
	e_scenario_type scenario_type;
	BYTE game_simulation[8];
	__int16 frame_limit;
	unsigned short __unknownE;
	unsigned char game_instance[8];
	unsigned long random_seed;
	unsigned long language;
	unsigned short campaign_insertion;
	unsigned long determinism_version;
	char game_variant[64516];
	unsigned long campaign_id;
	unsigned long map_id;
	char scenario_path[260];
	char scenario_zoneset_name[128];
	unsigned char __unknownFDB8;
	bool game_is_playtest;
	unsigned char __unknownFDBA[2];
	unsigned long m_game_playback;
	unsigned char __unknownFDC0[12];
	unsigned long campaign_difficulty;
	unsigned short campaign_insertion_point;
	unsigned char __unknownFDD2[2];
	unsigned long campaign_metagame_scoring;
	unsigned char campaign_metagame_scoring_enabled;
	unsigned char __unknownFDD9[3];
	unsigned long active_skulls;
	char campaign_armaments[112];
	unsigned char __unknownFE50[171];
	char map_variant[55724];
	unsigned char __unknown1D8A7;
	unsigned char __unknown1D8A8[120];
	s_player_options initial_participants[16];
};
static_assert(sizeof(s_game_options) == 0x1E9A0, "sizeof(s_game_options) != 0x1E9A0");
struct s_game_globals
{
	char __unknown0[4];
	unsigned __int32 active_structure_bsp_mask;
	unsigned __int32 __unknown8;
	unsigned __int32 __unknownC;
	s_game_options game_options;
	char __unknown1E9B0[1576];
	__int32 performance_throttle_profile_;
	char __unknown1EFDC[4];
};
static_assert(sizeof(s_game_globals) == 0x1EFE0, "sizeof(s_game_globals) != 0x1EFE0");

struct s_prop
{
	char __unknown0[0xB0];
};
static_assert(sizeof(s_prop) == 0xB0, "sizeof(s_prop) != 0xB0");

struct s_scripted_camera_globals
{
	char __unknown0[0xF4];
};
static_assert(sizeof(s_scripted_camera_globals) == 0xF4, "sizeof(s_scripted_camera_globals) != 0xF4");

struct s_effect
{
	char __unknown0[0xB0];
};
static_assert(sizeof(s_effect) == 0xB0, "sizeof(s_effect) != 0xB0");

struct s_command_scripts
{
	char __unknown0[0x1EC];
};
static_assert(sizeof(s_command_scripts) == 0x1EC, "sizeof(s_command_scripts) != 0x1EC");

struct s_cinematic_new_globals
{
	char __unknown0[0x1A4C];
};
static_assert(sizeof(s_cinematic_new_globals) == 0x1A4C, "sizeof(s_cinematic_new_globals) != 0x1A4C");

struct s_sound_sources
{
	char __unknown0[0x100];
};
static_assert(sizeof(s_sound_sources) == 0x100, "sizeof(s_sound_sources) != 0x100");

struct s_incident_globals
{
	char __unknown0[0x10B78];
};
static_assert(sizeof(s_incident_globals) == 0x10B78, "sizeof(s_incident_globals) != 0x10B78");

struct s_clump
{
	char __unknown0[0x10C];
};
static_assert(sizeof(s_clump) == 0x10C, "sizeof(s_clump) != 0x10C");

struct s_flocks
{
	char __unknown0[0xFC];
};
static_assert(sizeof(s_flocks) == 0xFC, "sizeof(s_flocks) != 0xFC");

struct s_game_time_globals
{
	bool initialized;
	unsigned __int8 __unknown1;
	unsigned __int16 flags;
	unsigned __int16 ticks_per_second;
	__int16 __unknown6;
	float seconds_per_tick;
	unsigned int elapsed_ticks;
	float gamespeed;
	float __unknown14;
	float __unknown18;
	float __unknown1C;
	float __unknown20;
	float __unknown24;
	unsigned int __unknown28;
	unsigned int __unknown2C;
	unsigned int __unknown30;
	unsigned int __unknown34;
	unsigned int __unknown38;
};
static_assert(sizeof(s_game_time_globals) == 0x3C, "sizeof(s_game_time_globals) != 0x3C");

struct s_render_texture_globals
{
	char __unknown0[0x68];
};
static_assert(sizeof(s_render_texture_globals) == 0x68, "sizeof(s_render_texture_globals) != 0x68");

struct s_rasterizer_game_states
{
	char __unknown0[0x204];
};
static_assert(sizeof(s_rasterizer_game_states) == 0x204, "sizeof(s_rasterizer_game_states) != 0x204");

struct s_object_looping_sounds
{
	char __unknown0[0x28];
};
static_assert(sizeof(s_object_looping_sounds) == 0x28, "sizeof(s_object_looping_sounds) != 0x28");

struct s_player_control_globals
{
	char __unknown0[0x930];
};
static_assert(sizeof(s_player_control_globals) == 0x930, "sizeof(s_player_control_globals) != 0x930");

struct s_performance
{
	char __unknown0[0x188];
};
static_assert(sizeof(s_performance) == 0x188, "sizeof(s_performance) != 0x188");

struct s_cinematic_globals
{
	char __unknown0[0x40];
};
static_assert(sizeof(s_cinematic_globals) == 0x40, "sizeof(s_cinematic_globals) != 0x40");

struct s_simulation_object_glue
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_simulation_object_glue) == 0xC, "sizeof(s_simulation_object_glue) != 0xC");

struct s_effect_event
{
	char __unknown0[0x14];
};
static_assert(sizeof(s_effect_event) == 0x14, "sizeof(s_effect_event) != 0x14");

struct s_stimulus
{
	char __unknown0[0x54];
};
static_assert(sizeof(s_stimulus) == 0x54, "sizeof(s_stimulus) != 0x54");

struct s_boids
{
	char __unknown0[0x40];
};
static_assert(sizeof(s_boids) == 0x40, "sizeof(s_boids) != 0x40");

struct s_gamestate_timing_samples
{
	char __unknown0[0x14];
};
static_assert(sizeof(s_gamestate_timing_samples) == 0x14, "sizeof(s_gamestate_timing_samples) != 0x14");

struct s_lights
{
	char __unknown0[0xC0];
};
static_assert(sizeof(s_lights) == 0xC0, "sizeof(s_lights) != 0xC0");

struct s_players_per_map_globals
{
	char __unknown0[0x7C];
};
static_assert(sizeof(s_players_per_map_globals) == 0x7C, "sizeof(s_players_per_map_globals) != 0x7C");

struct s_breakable_surface_globals
{
	char __unknown0[0x20DE0];
};
static_assert(sizeof(s_breakable_surface_globals) == 0x20DE0, "sizeof(s_breakable_surface_globals) != 0x20DE0");

struct s_players_globals
{
	char __unknown0[0x98];
};
static_assert(sizeof(s_players_globals) == 0x98, "sizeof(s_players_globals) != 0x98");

struct s_fire_team
{
	char __unknown0[0xD4];
};
static_assert(sizeof(s_fire_team) == 0xD4, "sizeof(s_fire_team) != 0xD4");

struct s_looping_sounds
{
	char __unknown0[0x1A0];
};
static_assert(sizeof(s_looping_sounds) == 0x1A0, "sizeof(s_looping_sounds) != 0x1A0");

struct s_object_globals
{
	char __unknown0[0x6030];
};
static_assert(sizeof(s_object_globals) == 0x6030, "sizeof(s_object_globals) != 0x6030");

struct s_game_save_globals
{
	char __unknown0[0x1C];
};
static_assert(sizeof(s_game_save_globals) == 0x1C, "sizeof(s_game_save_globals) != 0x1C");

struct s_player_training_globals
{
	char __unknown0[0xA08];
};
static_assert(sizeof(s_player_training_globals) == 0xA08, "sizeof(s_player_training_globals) != 0xA08");

struct s_chud_draw_user_globals
{
	char __unknown0[0x13EEE8];
};
static_assert(sizeof(s_chud_draw_user_globals) == 0x13EEE8, "sizeof(s_chud_draw_user_globals) != 0x13EEE8");

struct s_player_mapping_globals
{
	char __unknown0[0xE8];
};
static_assert(sizeof(s_player_mapping_globals) == 0xE8, "sizeof(s_player_mapping_globals) != 0xE8");

struct s_joint_state
{
	char __unknown0[0xAC];
};
static_assert(sizeof(s_joint_state) == 0xAC, "sizeof(s_joint_state) != 0xAC");

struct s_ai_directives
{
	char __unknown0[0xAC];
};
static_assert(sizeof(s_ai_directives) == 0xAC, "sizeof(s_ai_directives) != 0xAC");

struct s_collision_hierarchy_node_headers
{
	char __unknown0[0x1C];
};
static_assert(sizeof(s_collision_hierarchy_node_headers) == 0x1C, "sizeof(s_collision_hierarchy_node_headers) != 0x1C");

#pragma pack(push, 4)
struct c_director
{
	intptr_t __vftable;

	struct c_camera
	{
		intptr_t __vftable;

		int object_index;
		int __unknownC;
		int __unknown10;
		int __unknown14;
		float position[3];
		float yaw;
		float pitch;
		char __unknown2C[68];
	} m_camera;

	unsigned __int32 m_flags;

	struct s_observer
	{
		float position[3];
		float position_shift[3];
		float look;
		float look_shift;
		float depth;
		float field_of_view;
		float forward[3];
		float up[3];
		float direction[3];
	} m_observer;

	char __unknownC8[56];
	float m_position[3];
	char __unknown10C[112];

	float m_camera_speed;
	int m_controller_index;
	int m_player_mapping_index;
	char __unknown188[36];
};
#pragma pack(pop)
constexpr size_t sdg = offsetof(c_director, c_director::__unknown188);

struct s_director_globals
{
	//char __unknown0[0x6F0];

	c_director directors[4];
	char __unknown6B0[64];
};
static_assert(sizeof(s_director_globals) == 0x6F0, "sizeof(s_director_globals) != 0x6F0");

struct s_campaign_metagame_globals
{
	char __unknown0[0xFC];
};
static_assert(sizeof(s_campaign_metagame_globals) == 0xFC, "sizeof(s_campaign_metagame_globals) != 0xFC");

struct s_recycling_group
{
	char __unknown0[0x14];
};
static_assert(sizeof(s_recycling_group) == 0x14, "sizeof(s_recycling_group) != 0x14");

struct s_effect_location
{
	char __unknown0[0x4C];
};
static_assert(sizeof(s_effect_location) == 0x4C, "sizeof(s_effect_location) != 0x4C");

struct s_game_allegiance_globals
{
	char __unknown0[0x204];
};
static_assert(sizeof(s_game_allegiance_globals) == 0x204, "sizeof(s_game_allegiance_globals) != 0x204");

struct s_ai_player_state_globals
{
	char __unknown0[0xF0];
};
static_assert(sizeof(s_ai_player_state_globals) == 0xF0, "sizeof(s_ai_player_state_globals) != 0xF0");

struct s_multiplayer_sound_globals
{
	char __unknown0[0x590];
};
static_assert(sizeof(s_multiplayer_sound_globals) == 0x590, "sizeof(s_multiplayer_sound_globals) != 0x590");

struct s_vocalization_records
{
	char __unknown0[0x60];
};
static_assert(sizeof(s_vocalization_records) == 0x60, "sizeof(s_vocalization_records) != 0x60");

struct s_impacts
{
	char __unknown0[0x10C8];
};
static_assert(sizeof(s_impacts) == 0x10C8, "sizeof(s_impacts) != 0x10C8");

struct s_scripted_exposure_globals
{
	char __unknown0[0x34];
};
static_assert(sizeof(s_scripted_exposure_globals) == 0x34, "sizeof(s_scripted_exposure_globals) != 0x34");

struct s_player_effects
{
	char __unknown0[0x1148];
};
static_assert(sizeof(s_player_effects) == 0x1148, "sizeof(s_player_effects) != 0x1148");

struct s_collision_hierarchy_element_headers
{
	char __unknown0[0x30];
};
static_assert(sizeof(s_collision_hierarchy_element_headers) == 0x30, "sizeof(s_collision_hierarchy_element_headers) != 0x30");

struct s_object_early_movers
{
	char __unknown0[0x2688];
};
static_assert(sizeof(s_object_early_movers) == 0x2688, "sizeof(s_object_early_movers) != 0x2688");

struct s_airstrike
{
	char __unknown0[0x38];
};
static_assert(sizeof(s_airstrike) == 0x38, "sizeof(s_airstrike) != 0x38");

struct s_game_sound_globals
{
	char __unknown0[0x124];
};
static_assert(sizeof(s_game_sound_globals) == 0x124, "sizeof(s_game_sound_globals) != 0x124");

struct s_recycling_volumes
{
	char __unknown0[0x188];
};
static_assert(sizeof(s_recycling_volumes) == 0x188, "sizeof(s_recycling_volumes) != 0x188");

struct s_device_groups
{
	char __unknown0[0x10];
};
static_assert(sizeof(s_device_groups) == 0x10, "sizeof(s_device_groups) != 0x10");

struct s_cached_object_render_states
{
	char __unknown0[0x268];
};
static_assert(sizeof(s_cached_object_render_states) == 0x268, "sizeof(s_cached_object_render_states) != 0x268");

struct s_simulation_debug_globals
{
	char __unknown0[0x150];
};
static_assert(sizeof(s_simulation_debug_globals) == 0x150, "sizeof(s_simulation_debug_globals) != 0x150");

struct s_objectives
{
	char __unknown0[0x18];
};
static_assert(sizeof(s_objectives) == 0x18, "sizeof(s_objectives) != 0x18");

struct s_swarm
{
	char __unknown0[0x34];
};
static_assert(sizeof(s_swarm) == 0x34, "sizeof(s_swarm) != 0x34");

struct s_ai_sync_action_arranger
{
	char __unknown0[0x1D4];
};
static_assert(sizeof(s_ai_sync_action_arranger) == 0x1D4, "sizeof(s_ai_sync_action_arranger) != 0x1D4");

struct s_object_scripting
{
	char __unknown0[0x304];
};
static_assert(sizeof(s_object_scripting) == 0x304, "sizeof(s_object_scripting) != 0x304");

struct s_cloth
{
	char __unknown0[0x9D8];
};
static_assert(sizeof(s_cloth) == 0x9D8, "sizeof(s_cloth) != 0x9D8");

struct s_particle_system
{
	char __unknown0[0x54];
};
static_assert(sizeof(s_particle_system) == 0x54, "sizeof(s_particle_system) != 0x54");

struct s_hs_runtime_globals
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_hs_runtime_globals) == 0xC, "sizeof(s_hs_runtime_globals) != 0xC");

struct s_effect_counts
{
	char __unknown0[0x18];
};
static_assert(sizeof(s_effect_counts) == 0x18, "sizeof(s_effect_counts) != 0x18");

struct s_squad_group
{
	char __unknown0[0x24];
};
static_assert(sizeof(s_squad_group) == 0x24, "sizeof(s_squad_group) != 0x24");

struct s_breakable_surface_set_broken_events
{
	char __unknown0[0x468];
};
static_assert(sizeof(s_breakable_surface_set_broken_events) == 0x468, "sizeof(s_breakable_surface_set_broken_events) != 0x468");

struct s_main_time_globals
{
	char __unknown0[0x40];
};
static_assert(sizeof(s_main_time_globals) == 0x40, "sizeof(s_main_time_globals) != 0x40");

struct s_impact_globals
{
	char __unknown0[0x8C];
};
static_assert(sizeof(s_impact_globals) == 0x8C, "sizeof(s_impact_globals) != 0x8C");

struct s_sounds_effects
{
	char __unknown0[0x8C];
};
static_assert(sizeof(s_sounds_effects) == 0x8C, "sizeof(s_sounds_effects) != 0x8C");

struct s_widget
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_widget) == 0xC, "sizeof(s_widget) != 0xC");

struct s_local_game_engine_globals
{
	char __unknown0[0xDCB8];
};
static_assert(sizeof(s_local_game_engine_globals) == 0xDCB8, "sizeof(s_local_game_engine_globals) != 0xDCB8");

struct s_particle_emitter
{
	char __unknown0[0x94];
};
static_assert(sizeof(s_particle_emitter) == 0x94, "sizeof(s_particle_emitter) != 0x94");

struct s_particle_location
{
	char __unknown0[0x60];
};
static_assert(sizeof(s_particle_location) == 0x60, "sizeof(s_particle_location) != 0x60");

struct s_squad_patrol
{
	char __unknown0[0x6C4];
};
static_assert(sizeof(s_squad_patrol) == 0x6C4, "sizeof(s_squad_patrol) != 0x6C4");

struct s_leaf_system
{
	char __unknown0[0x4CC];
};
static_assert(sizeof(s_leaf_system) == 0x4CC, "sizeof(s_leaf_system) != 0x4CC");

struct s_damage_globals
{
	char __unknown0[0x810];
};
static_assert(sizeof(s_damage_globals) == 0x810, "sizeof(s_damage_globals) != 0x810");

struct s_havok_proxies
{
	char __unknown0[0x50];
};
static_assert(sizeof(s_havok_proxies) == 0x50, "sizeof(s_havok_proxies) != 0x50");

struct s_rumble
{
	char __unknown0[0x774];
};
static_assert(sizeof(s_rumble) == 0x774, "sizeof(s_rumble) != 0x774");

struct s_dynamic_firing_points
{
	char __unknown0[0x584];
};
static_assert(sizeof(s_dynamic_firing_points) == 0x584, "sizeof(s_dynamic_firing_points) != 0x584");

struct s_depth_of_field_globals
{
	char __unknown0[0x40];
};
static_assert(sizeof(s_depth_of_field_globals) == 0x40, "sizeof(s_depth_of_field_globals) != 0x40");

struct s_beam_system
{
	char __unknown0[0x2C];
};
static_assert(sizeof(s_beam_system) == 0x2C, "sizeof(s_beam_system) != 0x2C");

struct s_light_volume_system
{
	char __unknown0[0x2C];
};
static_assert(sizeof(s_light_volume_system) == 0x2C, "sizeof(s_light_volume_system) != 0x2C");

struct s_contrail_system
{
	char __unknown0[0x34];
};
static_assert(sizeof(s_contrail_system) == 0x34, "sizeof(s_contrail_system) != 0x34");

struct s_tracking
{
	char __unknown0[0xEC];
};
static_assert(sizeof(s_tracking) == 0xEC, "sizeof(s_tracking) != 0xEC");

struct s_stimulus_reference
{
	char __unknown0[0x20];
};
static_assert(sizeof(s_stimulus_reference) == 0x20, "sizeof(s_stimulus_reference) != 0x20");

struct s_sound_playback_controllers
{
	char __unknown0[0x1C];
};
static_assert(sizeof(s_sound_playback_controllers) == 0x1C, "sizeof(s_sound_playback_controllers) != 0x1C");

struct s_campaign_objectives
{
	char __unknown0[0xA0];
};
static_assert(sizeof(s_campaign_objectives) == 0xA0, "sizeof(s_campaign_objectives) != 0xA0");

struct s_screen_effect
{
	char __unknown0[0x2C];
};
static_assert(sizeof(s_screen_effect) == 0x2C, "sizeof(s_screen_effect) != 0x2C");

struct s_decal_system
{
	char __unknown0[0x60];
};
static_assert(sizeof(s_decal_system) == 0x60, "sizeof(s_decal_system) != 0x60");

struct s_physics_constants
{
	char __unknown0[0x20];
};
static_assert(sizeof(s_physics_constants) == 0x20, "sizeof(s_physics_constants) != 0x20");

struct s_path_influence
{
	char __unknown0[0x2738];
};
static_assert(sizeof(s_path_influence) == 0x2738, "sizeof(s_path_influence) != 0x2738");

struct s_prop_search
{
	char __unknown0[0x424];
};
static_assert(sizeof(s_prop_search) == 0x424, "sizeof(s_prop_search) != 0x424");

struct s_object_schedule_globals
{
	char __unknown0[0x27C];
};
static_assert(sizeof(s_object_schedule_globals) == 0x27C, "sizeof(s_object_schedule_globals) != 0x27C");

class c_particle_emitter_gpu
{
public:
	char __unknown0[0x1C];

	struct s_row
	{
		char __unknown0[0x14];
	};
	static_assert(sizeof(c_particle_emitter_gpu::s_row) == 0x14, "sizeof(c_particle_emitter_gpu::s_row) != 0x14");
};
static_assert(sizeof(c_particle_emitter_gpu) == 0x1C, "sizeof(c_particle_emitter_gpu) != 0x1C");

struct s_effect_geometry_sample
{
	char __unknown0[0x28];
};
static_assert(sizeof(s_effect_geometry_sample) == 0x28, "sizeof(s_effect_geometry_sample) != 0x28");

struct s_object_list_header
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_object_list_header) == 0xC, "sizeof(s_object_list_header) != 0xC");

struct s_hs_globals
{
	char __unknown0[0x8];
};
static_assert(sizeof(s_hs_globals) == 0x8, "sizeof(s_hs_globals) != 0x8");

struct s_formations
{
	char __unknown0[0x294];
};
static_assert(sizeof(s_formations) == 0x294, "sizeof(s_formations) != 0x294");

struct s_particles
{
	char __unknown0[0x8C];
};
static_assert(sizeof(s_particles) == 0x8C, "sizeof(s_particles) != 0x8C");

struct s_cheap_particle_emitters
{
	char __unknown0[0x2C];
};
static_assert(sizeof(s_cheap_particle_emitters) == 0x2C, "sizeof(s_cheap_particle_emitters) != 0x2C");

struct s_swarm_spawner
{
	char __unknown0[0x258];
};
static_assert(sizeof(s_swarm_spawner) == 0x258, "sizeof(s_swarm_spawner) != 0x258");

struct s_antenna
{
	char __unknown0[0x68];
};
static_assert(sizeof(s_antenna) == 0x68, "sizeof(s_antenna) != 0x68");

struct s_big_battle_squads
{
	char __unknown0[0x580];
};
static_assert(sizeof(s_big_battle_squads) == 0x580, "sizeof(s_big_battle_squads) != 0x580");

struct s_object_render_globals
{
	char __unknown0[0x18];
};
static_assert(sizeof(s_object_render_globals) == 0x18, "sizeof(s_object_render_globals) != 0x18");

struct s_rasterizer_implicit_geometry_data
{
	char __unknown0[0x54C4];
};
static_assert(sizeof(s_rasterizer_implicit_geometry_data) == 0x54C4, "sizeof(s_rasterizer_implicit_geometry_data) != 0x54C4");

struct s_render_hud_globals
{
	char __unknown0[0x540];
};
static_assert(sizeof(s_render_hud_globals) == 0x540, "sizeof(s_render_hud_globals) != 0x540");

struct s_beam_location
{
	char __unknown0[0x30];
};
static_assert(sizeof(s_beam_location) == 0x30, "sizeof(s_beam_location) != 0x30");

struct s_light_volume_location
{
	char __unknown0[0x2C];
};
static_assert(sizeof(s_light_volume_location) == 0x2C, "sizeof(s_light_volume_location) != 0x2C");

struct s_contrail_location
{
	char __unknown0[0x60];
};
static_assert(sizeof(s_contrail_location) == 0x60, "sizeof(s_contrail_location) != 0x60");

struct s_impact_arrarys
{
	char __unknown0[0x88];
};
static_assert(sizeof(s_impact_arrarys) == 0x88, "sizeof(s_impact_arrarys) != 0x88");

struct s_game_sound_scripted_impulses
{
	char __unknown0[0x200];
};
static_assert(sizeof(s_game_sound_scripted_impulses) == 0x200, "sizeof(s_game_sound_scripted_impulses) != 0x200");

struct s_looping_sounds_restore_state
{
	char __unknown0[0x28];
};
static_assert(sizeof(s_looping_sounds_restore_state) == 0x28, "sizeof(s_looping_sounds_restore_state) != 0x28");

struct s_water_physics_cache
{
	char __unknown0[0x9C];
};
static_assert(sizeof(s_water_physics_cache) == 0x9C, "sizeof(s_water_physics_cache) != 0x9C");

struct s_weather_globals_deterministic
{
	char __unknown0[0x9C];
};
static_assert(sizeof(s_weather_globals_deterministic) == 0x9C, "sizeof(s_weather_globals_deterministic) != 0x9C");

struct s_render_timing_samples
{
	char __unknown0[0x14];
};
static_assert(sizeof(s_render_timing_samples) == 0x14, "sizeof(s_render_timing_samples) != 0x14");

struct s_shield_render_cache_message
{
	char __unknown0[0x14];
};
static_assert(sizeof(s_shield_render_cache_message) == 0x14, "sizeof(s_shield_render_cache_message) != 0x14");

struct s_interaction_ripples
{
	char __unknown0[0x1400];
};
static_assert(sizeof(s_interaction_ripples) == 0x1400, "sizeof(s_interaction_ripples) != 0x1400");

struct s_beam
{
	char __unknown0[0x34];
};
static_assert(sizeof(s_beam) == 0x34, "sizeof(s_beam) != 0x34");

struct s_light_volume
{
	char __unknown0[0x34];
};
static_assert(sizeof(s_light_volume) == 0x34, "sizeof(s_light_volume) != 0x34");

struct s_contrail
{
	char __unknown0[0x4C];
};
static_assert(sizeof(s_contrail) == 0x4C, "sizeof(s_contrail) != 0x4C");

struct s_ragdolls
{
	char __unknown0[0x11C];
};
static_assert(sizeof(s_ragdolls) == 0x11C, "sizeof(s_ragdolls) != 0x11C");

struct s_lasing
{
	char __unknown0[0x68];
};
static_assert(sizeof(s_lasing) == 0x68, "sizeof(s_lasing) != 0x68");

struct s_cinematic_globals_non_deterministic
{
	char __unknown0[0x10];
};
static_assert(sizeof(s_cinematic_globals_non_deterministic) == 0x10, "sizeof(s_cinematic_globals_non_deterministic) != 0x10");

struct s_ai_cue
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_ai_cue) == 0xC, "sizeof(s_ai_cue) != 0xC");

struct s_character_properties_cache
{
	char __unknown0[0x664];
};
static_assert(sizeof(s_character_properties_cache) == 0x664, "sizeof(s_character_properties_cache) != 0x664");

class c_beam_gpu
{
public:
	char __unknown0[0x10];

	struct s_row
	{
		char __unknown0[0xC];
	};
	static_assert(sizeof(c_beam_gpu::s_row) == 0xC, "sizeof(c_beam_gpu::s_row) != 0xC");
};
static_assert(sizeof(c_beam_gpu) == 0x10, "sizeof(c_beam_gpu) != 0x10");

class c_light_volume_gpu
{
public:
	char __unknown0[0x10];

	struct s_row
	{
		char __unknown0[0xC];
	};
	static_assert(sizeof(c_light_volume_gpu::s_row) == 0xC, "sizeof(c_light_volume_gpu::s_row) != 0xC");
};
static_assert(sizeof(c_light_volume_gpu) == 0x10, "sizeof(c_light_volume_gpu) != 0x10");

struct s_campaign_metagame_globals_secondary
{
	char __unknown0[0x84];
};
static_assert(sizeof(s_campaign_metagame_globals_secondary) == 0x84, "sizeof(s_campaign_metagame_globals_secondary) != 0x84");

struct s_ai_reference_frame
{
	char __unknown0[0x4B0];
};
static_assert(sizeof(s_ai_reference_frame) == 0x4B0, "sizeof(s_ai_reference_frame) != 0x4B0");

struct s_object_activation_regions
{
	char __unknown0[0x28];
};
static_assert(sizeof(s_object_activation_regions) == 0x28, "sizeof(s_object_activation_regions) != 0x28");

struct s_lights_globals
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_lights_globals) == 0xC, "sizeof(s_lights_globals) != 0xC");

class c_contrail_gpu
{
public:
	char __unknown0[0x10];

	struct s_row
	{
		char __unknown0[0x14];
	};
	static_assert(sizeof(c_contrail_gpu::s_row) == 0x14, "sizeof(c_contrail_gpu::s_row) != 0x14");
};
static_assert(sizeof(c_contrail_gpu) == 0x10, "sizeof(c_contrail_gpu) != 0x10");

struct s_recorded_animations
{
	char __unknown0[0xB8];
};
static_assert(sizeof(s_recorded_animations) == 0xB8, "sizeof(s_recorded_animations) != 0xB8");

struct s_kill_trigger_volume_state
{
	char __unknown0[0x30];
};
static_assert(sizeof(s_kill_trigger_volume_state) == 0x30, "sizeof(s_kill_trigger_volume_state) != 0x30");

struct s_weather_globals_render
{
	char __unknown0[0xD0];
};
static_assert(sizeof(s_weather_globals_render) == 0xD0, "sizeof(s_weather_globals_render) != 0xD0");

struct s_contrail_profile
{
	char __unknown0[0x4C];
};
static_assert(sizeof(s_contrail_profile) == 0x4C, "sizeof(s_contrail_profile) != 0x4C");

struct s_megalo_objects
{
	char __unknown0[0x84];
};
static_assert(sizeof(s_megalo_objects) == 0x84, "sizeof(s_megalo_objects) != 0x84");

struct s_game_sound_globals_main
{
	char __unknown0[0x10];
};
static_assert(sizeof(s_game_sound_globals_main) == 0x10, "sizeof(s_game_sound_globals_main) != 0x10");

struct s_object_name_list
{
	char __unknown0[0x2000];
};
static_assert(sizeof(s_object_name_list) == 0x2000, "sizeof(s_object_name_list) != 0x2000");

struct s_weather_globals_shared
{
	char __unknown0[0x100];
};
static_assert(sizeof(s_weather_globals_shared) == 0x100, "sizeof(s_weather_globals_shared) != 0x100");

struct s_decal
{
	char __unknown0[0x84];
};
static_assert(sizeof(s_decal) == 0x84, "sizeof(s_decal) != 0x84");

struct s_list_object_reference
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_list_object_reference) == 0xC, "sizeof(s_list_object_reference) != 0xC");

struct s_sound_classes
{
	char __unknown0[0xF88];
};
static_assert(sizeof(s_sound_classes) == 0xF88, "sizeof(s_sound_classes) != 0xF88");

struct s_object_placement_globals
{
	char __unknown0[0x104];
};
static_assert(sizeof(s_object_placement_globals) == 0x104, "sizeof(s_object_placement_globals) != 0x104");

struct s_hue_saturation_control
{
	char __unknown0[0x14];
};
static_assert(sizeof(s_hue_saturation_control) == 0x14, "sizeof(s_hue_saturation_control) != 0x14");

struct s_effect_messaging_queue
{
	char __unknown0[0xB84C];
};
static_assert(sizeof(s_effect_messaging_queue) == 0xB84C, "sizeof(s_effect_messaging_queue) != 0xB84C");

struct s_collision_hierarchy_node_hash_table
{
	char __unknown0[0x24008];
};
static_assert(sizeof(s_collision_hierarchy_node_hash_table) == 0x24008, "sizeof(s_collision_hierarchy_node_hash_table) != 0x24008");

struct s_collision_hierarchy_globals
{
	char __unknown0[0x840];
};
static_assert(sizeof(s_collision_hierarchy_globals) == 0x840, "sizeof(s_collision_hierarchy_globals) != 0x840");

struct s_player_control_globals_deterministic
{
	char __unknown0[0x40];
};
static_assert(sizeof(s_player_control_globals_deterministic) == 0x40, "sizeof(s_player_control_globals_deterministic) != 0x40");

struct s_performance_runtime_definition
{
	char __unknown0[0x3C0];
};
static_assert(sizeof(s_performance_runtime_definition) == 0x3C0, "sizeof(s_performance_runtime_definition) != 0x3C0");

struct s_vocalization_timers
{
	char __unknown0[0xFB8];
};
static_assert(sizeof(s_vocalization_timers) == 0xFB8, "sizeof(s_vocalization_timers) != 0xFB8");

struct s_big_battle_squad_units
{
	char __unknown0[0xC800];
};
static_assert(sizeof(s_big_battle_squad_units) == 0xC800, "sizeof(s_big_battle_squad_units) != 0xC800");

struct s_non_deterministic_hs_thread
{
	char __unknown0[0x52C];
};
static_assert(sizeof(s_non_deterministic_hs_thread) == 0x52C, "sizeof(s_non_deterministic_hs_thread) != 0x52C");

struct s_simulated_input
{
	char __unknown0[0x2400];
};
static_assert(sizeof(s_simulated_input) == 0x2400, "sizeof(s_simulated_input) != 0x2400");

struct s_bink_gamestate
{
	char __unknown0[0x8];
};
static_assert(sizeof(s_bink_gamestate) == 0x8, "sizeof(s_bink_gamestate) != 0x8");

struct s_object_messaging_queue
{
	char __unknown0[0x410C];
};
static_assert(sizeof(s_object_messaging_queue) == 0x410C, "sizeof(s_object_messaging_queue) != 0x410C");

struct s_decal_messaging_queue
{
	char __unknown0[0x82C];
};
static_assert(sizeof(s_decal_messaging_queue) == 0x82C, "sizeof(s_decal_messaging_queue) != 0x82C");

struct s_director_scripting
{
	bool scripting_enabled;
};
static_assert(sizeof(s_director_scripting) == 0x1, "sizeof(s_director_scripting) != 0x1");

struct s_chud_persistent_global_data
{
	char __unknown0[0xCA20];
};
static_assert(sizeof(s_chud_persistent_global_data) == 0xCA20, "sizeof(s_chud_persistent_global_data) != 0xCA20");

struct s_effect_lightprobes
{
	char __unknown0[0x6C00];
};
static_assert(sizeof(s_effect_lightprobes) == 0x6C00, "sizeof(s_effect_lightprobes) != 0x6C00");

struct s_scenario_interpolator_states
{
	char __unknown0[0x180];
};
static_assert(sizeof(s_scenario_interpolator_states) == 0x180, "sizeof(s_scenario_interpolator_states) != 0x180");

struct s_deterministic_game_sound_globals
{
	char __unknown0[0x1300];
};
static_assert(sizeof(s_deterministic_game_sound_globals) == 0x1300, "sizeof(s_deterministic_game_sound_globals) != 0x1300");

struct s_spawner_globals
{
	char __unknown0[0x2];
};
static_assert(sizeof(s_spawner_globals) == 0x2, "sizeof(s_spawner_globals) != 0x2");

struct s_observer_gamestate_globals
{
	char __unknown0[0xC];
};
static_assert(sizeof(s_observer_gamestate_globals) == 0xC, "sizeof(s_observer_gamestate_globals) != 0xC");

struct s_havok_gamestate
{
	char __unknown0[0x8];
};
static_assert(sizeof(s_havok_gamestate) == 0x8, "sizeof(s_havok_gamestate) != 0x8");

struct s_chud_persistent_user_data
{
	char __unknown0[0x43280];
};
static_assert(sizeof(s_chud_persistent_user_data) == 0x43280, "sizeof(s_chud_persistent_user_data) != 0x43280");

struct s_render_game_globals
{
	char __unknown0[0xCD0];
};
static_assert(sizeof(s_render_game_globals) == 0xCD0, "sizeof(s_render_game_globals) != 0xCD0");

struct s_game_sound_player_effects_globals
{
	char __unknown0[0x18];
};
static_assert(sizeof(s_game_sound_player_effects_globals) == 0x18, "sizeof(s_game_sound_player_effects_globals) != 0x18");

struct s_breakable_surface_redirection_table
{
	char __unknown0[0x40068];
};
static_assert(sizeof(s_breakable_surface_redirection_table) == 0x40068, "sizeof(s_breakable_surface_redirection_table) != 0x40068");

struct s_soft_surface_globals
{
	char __unknown0[0x10];
};
static_assert(sizeof(s_soft_surface_globals) == 0x10, "sizeof(s_soft_surface_globals) != 0x10");

struct s_task_records
{
	char __unknown0[0x2EE00];
};
static_assert(sizeof(s_task_records) == 0x2EE00, "sizeof(s_task_records) != 0x2EE00");

struct s_game_heat_globals
{
	char __unknown0[0x80];
};
static_assert(sizeof(s_game_heat_globals) == 0x80, "sizeof(s_game_heat_globals) != 0x80");

struct s_cinematic_light_globals
{
	char __unknown0[0x52C8];
};
static_assert(sizeof(s_cinematic_light_globals) == 0x52C8, "sizeof(s_cinematic_light_globals) != 0x52C8");

struct s_random_math
{
	int deterministic_ramdom_seed;
};
static_assert(sizeof(s_random_math) == 0x4, "sizeof(s_random_math) != 0x4");

struct s_visibility_active_portals
{
	char __unknown0[0x800];
};
static_assert(sizeof(s_visibility_active_portals) == 0x800, "sizeof(s_visibility_active_portals) != 0x800");

struct s_game_engine_render_globals
{
	char __unknown0[0xE38];
};
static_assert(sizeof(s_game_engine_render_globals) == 0xE38, "sizeof(s_game_engine_render_globals) != 0xE38");

struct s_cloth_globals
{
	char __unknown0[0x7900];
};
static_assert(sizeof(s_cloth_globals) == 0x7900, "sizeof(s_cloth_globals) != 0x7900");

struct s_object_render_data
{
	char __unknown0[0x2000];
};
static_assert(sizeof(s_object_render_data) == 0x2000, "sizeof(s_object_render_data) != 0x2000");

struct s_first_person_orientations
{
	char __unknown0[0xF000];
};
static_assert(sizeof(s_first_person_orientations) == 0xF000, "sizeof(s_first_person_orientations) != 0xF000");

struct s_observer_globals
{
	char __unknown0[0x1050];
};
static_assert(sizeof(s_observer_globals) == 0x1050, "sizeof(s_observer_globals) != 0x1050");

struct s_first_person_weapons
{
	char __unknown0[0x14EA0];
};
static_assert(sizeof(s_first_person_weapons) == 0x14EA0, "sizeof(s_first_person_weapons) != 0x14EA0");

struct s_havok_contact_point_globals
{
	char __unknown0[0x10001];
};
static_assert(sizeof(s_havok_contact_point_globals) == 0x10001, "sizeof(s_havok_contact_point_globals) != 0x10001");

struct s_chud_widgets
{
	char __unknown0[0x20];
};
static_assert(sizeof(s_chud_widgets) == 0x20, "sizeof(s_chud_widgets) != 0x20");

struct s_usability_globals
{
	char __unknown0[0x201];
};
static_assert(sizeof(s_usability_globals) == 0x201, "sizeof(s_usability_globals) != 0x201");


typedef c_data_array<s_object, 2048> c_object_data_array;
typedef c_data_array<s_actor, 96> c_actor_data_array;
typedef c_data_array<s_players, 16> c_players_data_array;
struct s_game_engine_globals;
struct s_ai_globals;
typedef c_data_array<s_prop_reference, 1024> c_prop_reference_data_array;
typedef c_data_array<s_deterministic_hs_thread, 320> c_deterministic_hs_thread_data_array;
typedef c_data_array<s_squad, 256> c_squad_data_array;
struct s_game_globals;
typedef c_data_array<s_prop, 256> c_prop_data_array;
struct s_scripted_camera_globals;
typedef c_data_array<s_effect, 920> c_effect_data_array;
typedef c_data_array<s_command_scripts, 64> c_command_scripts_data_array;
struct s_cinematic_new_globals;
typedef c_data_array<s_sound_sources, 384> c_sound_sources_data_array;
struct s_incident_globals;
typedef c_data_array<s_clump, 20> c_clump_data_array;
typedef c_data_array<s_flocks, 10> c_flocks_data_array;
struct s_game_time_globals;
struct s_render_texture_globals;
struct s_rasterizer_game_states;
struct s_global_preferences;
typedef c_data_array<s_object_looping_sounds, 1024> c_object_looping_sounds_data_array;
struct s_player_control_globals;
typedef c_data_array<s_performance, 32> c_performance_data_array;
struct s_cinematic_globals;
typedef c_data_array<s_simulation_object_glue, 2048> c_simulation_object_glue_data_array;
typedef c_data_array<s_effect_event, 1800> c_effect_event_data_array;
typedef c_data_array<s_stimulus, 256> c_stimulus_data_array;
typedef c_data_array<s_boids, 1024> c_boids_data_array;
struct s_gamestate_timing_samples;
typedef c_data_array<s_lights, 600> c_lights_data_array;
struct s_players_per_map_globals;
struct s_breakable_surface_globals;
struct s_players_globals;
typedef c_data_array<s_fire_team, 16> c_fire_team_data_array;
typedef c_data_array<s_looping_sounds, 128> c_looping_sounds_data_array;
struct s_object_globals;
struct s_game_save_globals;
struct s_player_training_globals;
struct s_chud_draw_user_globals;
struct s_player_mapping_globals;
typedef c_data_array<s_joint_state, 20> c_joint_state_data_array;
typedef c_data_array<s_ai_directives, 16> c_ai_directives_data_array;
typedef c_data_array<s_collision_hierarchy_node_headers, 6144> c_collision_hierarchy_node_headers_data_array;
struct s_director_globals;
struct s_campaign_metagame_globals;
typedef c_data_array<s_recycling_group, 128> c_recycling_group_data_array;
typedef c_data_array<s_effect_location, 1380> c_effect_location_data_array;
struct s_game_allegiance_globals;
struct s_ai_player_state_globals;
struct s_multiplayer_sound_globals;
typedef c_data_array<s_vocalization_records, 15> c_vocalization_records_data_array;
typedef c_data_array<s_impacts, 32> c_impacts_data_array;
struct s_scripted_exposure_globals;
struct s_player_effects;
typedef c_data_array<s_collision_hierarchy_element_headers, 7168> c_collision_hierarchy_element_headers_data_array;
struct s_object_early_movers;
struct s_airstrike;
struct s_game_sound_globals;
struct s_recycling_volumes;
typedef c_data_array<s_device_groups, 1024> c_device_groups_data_array;
typedef c_data_array<s_cached_object_render_states, 512> c_cached_object_render_states_data_array;
struct s_simulation_debug_globals;
typedef c_data_array<s_objectives, 64> c_objectives_data_array;
typedef c_data_array<s_swarm, 32> c_swarm_data_array;
typedef c_data_array<s_ai_sync_action_arranger, 32> c_ai_sync_action_arranger_data_array;
struct s_object_scripting;
typedef c_data_array<s_cloth, 8> c_cloth_data_array;
typedef c_data_array<s_particle_system, 576> c_particle_system_data_array;
struct s_hs_runtime_globals;
struct s_effect_counts;
typedef c_data_array<s_squad_group, 130> c_squad_group_data_array;
typedef c_data_array<s_breakable_surface_set_broken_events, 64> c_breakable_surface_set_broken_events_data_array;
struct s_main_time_globals;
struct s_impact_globals;
typedef c_data_array<s_sounds_effects, 16> c_sounds_effects_data_array;
typedef c_data_array<s_widget, 64> c_widget_data_array;
struct s_local_game_engine_globals;
typedef c_data_array<s_particle_emitter, 832> c_particle_emitter_data_array;
typedef c_data_array<s_particle_location, 576> c_particle_location_data_array;
typedef c_data_array<s_squad_patrol, 16> c_squad_patrol_data_array;
typedef c_data_array<s_leaf_system, 24> c_leaf_system_data_array;
struct s_damage_globals;
typedef c_data_array<s_havok_proxies, 16> c_havok_proxies_data_array;
struct s_rumble;
typedef c_data_array<s_dynamic_firing_points, 15> c_dynamic_firing_points_data_array;
struct s_depth_of_field_globals;
typedef c_data_array<s_beam_system, 160> c_beam_system_data_array;
typedef c_data_array<s_light_volume_system, 160> c_light_volume_system_data_array;
typedef c_data_array<s_contrail_system, 160> c_contrail_system_data_array;
typedef c_data_array<s_tracking, 100> c_tracking_data_array;
typedef c_data_array<s_stimulus_reference, 1024> c_stimulus_reference_data_array;
typedef c_data_array<s_sound_playback_controllers, 64> c_sound_playback_controllers_data_array;
typedef c_data_array<s_screen_effect, 64> c_screen_effect_data_array;
struct s_campaign_objectives;
typedef c_data_array<s_decal_system, 704> c_decal_system_data_array;
struct s_physics_constants;
typedef c_data_array<s_path_influence, 2> c_path_influence_data_array;
typedef c_data_array<s_prop_search, 32> c_prop_search_data_array;
struct s_data_pool;
struct s_object_schedule_globals;
typedef c_data_array<c_particle_emitter_gpu, 832> c_particle_emitter_gpu_data_array;
typedef c_data_array<s_effect_geometry_sample, 128> c_effect_geometry_sample_data_array;
typedef c_data_array<s_object_list_header, 48> c_object_list_header_data_array;
typedef c_data_array<s_hs_globals, 4096> c_hs_globals_data_array;
typedef c_data_array<s_formations, 16> c_formations_data_array;
typedef c_data_array<s_particles, 2048> c_particles_data_array;
typedef c_data_array<s_cheap_particle_emitters, 200> c_cheap_particle_emitters_data_array;
struct s_swarm_spawner;
typedef c_data_array<s_antenna, 12> c_antenna_data_array;
struct s_big_battle_squads;
struct s_object_render_globals;
struct s_rasterizer_implicit_geometry_data;
typedef c_data_array<c_particle_emitter_gpu::s_row, 448> c_particle_emitter_gpu_row_data_array;
struct s_render_hud_globals;
typedef c_data_array<s_beam_location, 160> c_beam_location_data_array;
typedef c_data_array<s_light_volume_location, 160> c_light_volume_location_data_array;
typedef c_data_array<s_contrail_location, 160> c_contrail_location_data_array;
typedef c_data_array<s_impact_arrarys, 32> c_impact_arrarys_data_array;
struct s_game_sound_scripted_impulses;
typedef c_data_array<s_looping_sounds_restore_state, 128> c_looping_sounds_restore_state_data_array;
typedef c_data_array<s_water_physics_cache, 96> c_water_physics_cache_data_array;
struct s_weather_globals_deterministic;
struct s_render_timing_samples;
typedef c_data_array<s_shield_render_cache_message, 8> c_shield_render_cache_message_data_array;
struct s_interaction_ripples;
typedef c_data_array<s_beam, 160> c_beam_data_array;
typedef c_data_array<s_light_volume, 160> c_light_volume_data_array;
typedef c_data_array<s_contrail, 160> c_contrail_data_array;
typedef c_data_array<s_ragdolls, 7> c_ragdolls_data_array;
typedef c_data_array<s_lasing, 20> c_lasing_data_array;
struct s_cinematic_globals_non_deterministic;
typedef c_data_array<s_ai_cue, 256> c_ai_cue_data_array;
typedef c_data_array<s_character_properties_cache, 40> c_character_properties_cache_data_array;
typedef c_data_array<c_beam_gpu, 160> c_beam_gpu_data_array;
typedef c_data_array<c_light_volume_gpu, 160> c_light_volume_gpu_data_array;
struct s_campaign_metagame_globals_secondary;
struct s_ai_reference_frame;
typedef c_data_array<s_object_activation_regions, 128> c_object_activation_regions_data_array;
struct s_lights_globals;
typedef c_data_array<c_contrail_gpu, 160> c_contrail_gpu_data_array;
typedef c_data_array<c_contrail_gpu::s_row, 160> c_contrail_gpu_row_data_array;
typedef c_data_array<s_recorded_animations, 1> c_recorded_animations_data_array;
struct s_kill_trigger_volume_state;
typedef c_data_array<c_beam_gpu::s_row, 160> c_beam_gpu_row_data_array;
typedef c_data_array<c_light_volume_gpu::s_row, 160> c_light_volume_gpu_row_data_array;
struct s_weather_globals_render;
typedef c_data_array<s_contrail_profile, 1> c_contrail_profile_data_array;
typedef c_data_array<s_megalo_objects, 256> c_megalo_objects_data_array;
struct s_game_sound_globals_main;
struct s_object_name_list;
struct s_weather_globals_shared;
typedef c_data_array<s_decal, 2048> c_decal_data_array;
typedef c_data_array<s_list_object_reference, 128> c_list_object_reference_data_array;
struct s_sound_classes;
struct s_object_placement_globals;
struct s_hue_saturation_control;
struct s_effect_messaging_queue;
struct s_collision_hierarchy_node_hash_table;
struct s_collision_hierarchy_globals;
struct s_player_control_globals_deterministic *player_control_globals_deterministic;
typedef c_data_array<s_performance_runtime_definition, 32> c_performance_runtime_definition_data_array;
struct s_vocalization_timers;
struct s_big_battle_squad_units;
typedef c_data_array<s_non_deterministic_hs_thread, 320> c_non_deterministic_hs_thread_data_array;
struct s_simulated_input;
struct s_bink_gamestate;
struct s_object_messaging_queue;
struct s_decal_messaging_queue;
struct s_director_scripting;
struct s_chud_persistent_global_data;
struct s_effect_lightprobes;
struct s_scenario_interpolator_states;
struct s_deterministic_game_sound_globals;
struct s_spawner_globals;
struct s_observer_gamestate_globals;
struct s_havok_gamestate;
struct s_chud_persistent_user_data;
struct s_render_game_globals;
struct s_game_sound_player_effects_globals;
struct s_breakable_surface_redirection_table;
struct s_soft_surface_globals;
struct s_task_records;
struct s_game_heat_globals;
struct s_cinematic_light_globals;
struct s_random_math;
struct s_visibility_active_portals;
struct s_game_engine_render_globals;
struct s_cloth_globals;
struct s_object_render_data;
struct s_first_person_orientations;
struct s_observer_globals;
struct s_first_person_weapons;
struct s_havok_contact_point_globals;
typedef c_data_array<s_chud_widgets, 128> c_chud_widgets_data_array;
struct s_usability_globals;

struct s_thread_local_storage
{
	void *__unknown000;
	c_object_data_array *object_data;
	c_actor_data_array *actor_data;
	c_players_data_array *players_data;
	s_game_engine_globals *game_engine_globals;
	void *threading28;
	s_ai_globals *ai_globals;
	c_prop_reference_data_array *prop_reference_data;
	c_deterministic_hs_thread_data_array *deterministic_hs_thread_data;
	c_squad_data_array *squad_data;
	s_game_globals *game_globals;
	c_prop_data_array *prop_data;
	s_scripted_camera_globals *scripted_camera_globals;
	c_effect_data_array *effect_data;
	c_command_scripts_data_array *command_scripts_data;
	s_cinematic_new_globals *cinematic_new_globals;
	void *__unknown080;
	void *__unknown088;
	c_sound_sources_data_array *sound_sources_data;
	s_incident_globals *incident_globals;
	c_clump_data_array *clump_data;
	c_flocks_data_array *flocks_data;
	s_game_time_globals *game_time_globals;
	s_render_texture_globals *render_texture_globals;
	s_rasterizer_game_states *rasterizer_game_states;
	s_global_preferences *global_preferences;
	c_object_looping_sounds_data_array *object_looping_sounds_data;
	s_player_control_globals *player_control_globals;
	c_performance_data_array *performance_data;
	s_cinematic_globals *cinematic_globals;
	c_simulation_object_glue_data_array *simulation_object_glue_data;
	c_effect_event_data_array *effect_event_data;
	c_stimulus_data_array *stimulus_data;
	c_boids_data_array *boids_data;
	s_gamestate_timing_samples *gamestate_timing_samples;
	c_lights_data_array *lights_data;
	s_players_per_map_globals *players_per_map_globals;
	s_breakable_surface_globals *breakable_surface_globals;
	s_players_globals *players_globals;
	c_fire_team_data_array *fire_team_data;
	c_looping_sounds_data_array *looping_sounds_data;
	s_object_globals *object_globals;
	s_game_save_globals *game_save_globals;
	s_player_training_globals *player_training_globals;
	s_chud_draw_user_globals *chud_draw_user_globals;
	s_player_mapping_globals *player_mapping_globals;
	c_joint_state_data_array *joint_state_data;
	c_ai_directives_data_array *ai_directives_data;
	c_collision_hierarchy_node_headers_data_array *collision_hierarchy_node_headers_data;
	s_director_globals *director_globals;
	s_campaign_metagame_globals *campaign_metagame_globals;
	c_recycling_group_data_array *recycling_group_data;
	c_effect_location_data_array *effect_location_data;
	s_game_allegiance_globals *game_allegiance_globals;
	s_ai_player_state_globals *ai_player_state_globals;
	s_multiplayer_sound_globals *multiplayer_sound_globals;
	c_vocalization_records_data_array *vocalization_records_data;
	c_impacts_data_array *impacts_data;
	s_scripted_exposure_globals *scripted_exposure_globals;
	s_player_effects *player_effects;
	c_collision_hierarchy_element_headers_data_array *collision_hierarchy_element_headers_data;
	void *font_character_data;
	s_object_early_movers *object_early_movers;
	s_airstrike *airstrike;
	s_game_sound_globals *game_sound_globals;
	s_recycling_volumes *recycling_volumes;
	c_device_groups_data_array *device_groups_data;
	c_cached_object_render_states_data_array *cached_object_render_states_data;
	s_simulation_debug_globals *simulation_debug_globals;
	c_objectives_data_array *objectives_data;
	c_swarm_data_array *swarm_data;
	c_ai_sync_action_arranger_data_array *ai_sync_action_arranger_data;
	s_object_scripting *object_scripting;
	c_cloth_data_array *cloth_data;
	c_particle_system_data_array *particle_system_data;
	s_hs_runtime_globals *hs_runtime_globals;
	void *__unknown260;
	s_effect_counts *effect_counts;
	c_squad_group_data_array *squad_group_data;
	c_breakable_surface_set_broken_events_data_array *breakable_surface_set_broken_event_data;
	s_main_time_globals *main_time_globals;
	s_impact_globals *impact_globals;
	c_sounds_effects_data_array *sounds_effects_data;
	c_widget_data_array *widget_data;
	s_local_game_engine_globals *local_game_engine_globals;
	c_particle_emitter_data_array *particle_emitter_data;
	c_particle_location_data_array *particle_location_data;
	c_squad_patrol_data_array *squad_patrol_data;
	c_leaf_system_data_array *leaf_system_data;
	s_damage_globals *damage_globals;
	c_havok_proxies_data_array *havok_proxies_data;
	s_rumble *rumble;
	c_dynamic_firing_points_data_array *dynamic_firing_points_data;
	s_depth_of_field_globals *depth_of_field_globals;
	c_beam_system_data_array *beam_system_data;
	c_light_volume_system_data_array *light_volume_system_data;
	c_contrail_system_data_array *contrail_system_data;
	c_tracking_data_array *tracking_data;
	c_stimulus_reference_data_array *stimulus_reference_data;
	c_sound_playback_controllers_data_array *sound_playback_controllers_data;
	s_campaign_objectives *campaign_objectives;
	c_screen_effect_data_array *screen_effect_data;
	c_decal_system_data_array *decal_system_data;
	s_physics_constants *physics_constants;
	void *threading340;
	c_path_influence_data_array *path_influence_data;
	c_prop_search_data_array *prop_search_data;
	s_data_pool *objects_pool;
	s_object_schedule_globals *object_schedule_globals;
	c_particle_emitter_gpu_data_array *c_particle_emitter_gpu_data;
	c_effect_geometry_sample_data_array *effect_geometry_sample_data;
	c_object_list_header_data_array *object_list_header_data;
	c_hs_globals_data_array *hs_globals_data;
	c_formations_data_array *formations_data;
	c_particles_data_array *particles_data;
	c_cheap_particle_emitters_data_array *cheap_particle_emitters_data;
	s_swarm_spawner *swarm_spawner;
	c_antenna_data_array *antenna_data;
	s_big_battle_squads *big_battle_squads;
	s_object_render_globals *object_render_globals;
	s_rasterizer_implicit_geometry_data *rasterizer_implicit_geometry_data;
	c_particle_emitter_gpu_row_data_array *particle_emitter_gpu_row_data;
	s_render_hud_globals *render_hud_globals;
	c_beam_location_data_array *beam_location_data;
	c_light_volume_location_data_array *light_volume_location_data;
	c_contrail_location_data_array *contrail_location_data;
	s_impact_arrarys *impact_arrays_data;
	s_game_sound_scripted_impulses *game_sound_scripted_impulses;
	c_looping_sounds_restore_state_data_array *looping_sounds_restore_state_data;
	c_water_physics_cache_data_array *water_physics_cache_data;
	s_weather_globals_deterministic *weather_globals_deterministic;
	s_render_timing_samples *render_timing_samples;
	c_shield_render_cache_message_data_array *shield_render_cache_message_data;
	s_interaction_ripples *interaction_ripples;
	c_beam_data_array *beam_data;
	c_light_volume_data_array *light_volume_data;
	c_contrail_data_array *contrail_data;
	c_ragdolls_data_array *ragdolls_data;
	c_lasing_data_array *lasing_data;
	s_cinematic_globals_non_deterministic *cinematic_globals_non_deterministic;
	c_ai_cue_data_array *ai_cue_data;
	c_character_properties_cache_data_array *character_properties_cache_data;
	c_beam_gpu_data_array *beam_gpu_data;
	c_light_volume_gpu_data_array *light_volume_gpu_data;
	void *__unknown480;
	s_campaign_metagame_globals_secondary *campaign_metagame_globals_secondary;
	s_ai_reference_frame *ai_reference_frame;
	c_object_activation_regions_data_array *object_activation_regions_data;
	s_lights_globals *lights_globals;
	c_contrail_gpu_data_array *contrail_gpu_data;
	c_contrail_gpu_row_data_array *contrail_gpu_row_data;
	c_recorded_animations_data_array *recorded_animations_data;
	s_kill_trigger_volume_state *kill_trigger_volume_state;
	c_beam_gpu_row_data_array *beam_gpu_row_data;
	c_light_volume_gpu_row_data_array *light_volume_gpu_row_data;
	s_weather_globals_render *weather_globals_render;
	c_contrail_profile_data_array *contrail_profile_data;
	c_megalo_objects_data_array *megalo_objects_data;
	s_game_sound_globals_main *game_sound_globals_main;
	void *__unknown4F8;
	s_object_name_list *object_name_list;
	s_weather_globals_shared *weather_globals_shared;
	c_decal_data_array *decal_data;
	c_list_object_reference_data_array *list_object_reference_data;
	s_sound_classes *sound_classes;
	s_object_placement_globals *object_placement_globals;
	s_hue_saturation_control *hue_saturation_control;
	s_effect_messaging_queue *effect_messaging_queue;
	s_collision_hierarchy_node_hash_table *collision_hierarchy_node_hash_table;
	s_collision_hierarchy_globals *collision_hierarchy_globals;
	s_player_control_globals_deterministic *player_control_globals_deterministic;
	c_performance_runtime_definition_data_array *performance_runtime_definition_data;
	s_vocalization_timers *vocalization_timers;
	s_big_battle_squad_units *big_battle_squad_units;
	c_non_deterministic_hs_thread_data_array *non_deterministic_hs_thread_data;
	s_simulated_input *simulated_input;
	s_bink_gamestate *bink_gamestate;
	s_object_messaging_queue *object_messaging_queue;
	s_decal_messaging_queue *decal_messaging_queue;
	s_director_scripting *director_scripting;
	void *__unknown5A0;
	s_chud_persistent_global_data *chud_persistent_global_data;
	s_effect_lightprobes *effect_lightprobes;
	s_scenario_interpolator_states *scenario_interpolator_states;
	s_deterministic_game_sound_globals *deterministic_game_sound_globals;
	s_spawner_globals *spawner_globals;
	s_observer_gamestate_globals *observer_gamestate_globals;
	s_havok_gamestate *havok_gamestate;
	s_chud_persistent_user_data *chud_persistent_user_data;
	void *beam_gpu;
	void *light_volume_gpu;
	void *contrail_gpu;
	void *particle_emitter_gpu;
	s_render_game_globals *render_game_globals;
	s_game_sound_player_effects_globals *game_sound_player_effects_globals;
	s_breakable_surface_redirection_table *breakable_surface_redirection_table;
	s_soft_surface_globals *soft_surface_globals;
	s_task_records *task_records;
	void *__unknown630;
	void *__unknown638;
	s_game_heat_globals *game_heat_globals;
	s_cinematic_light_globals *cinematic_light_globals;
	s_random_math *random_math;
	s_visibility_active_portals *visibility_active_portals;
	s_game_engine_render_globals *game_engine_render_globals;
	s_cloth_globals *cloth_globals;
	s_object_render_data *object_render_data;
	s_first_person_orientations *first_person_orientations;
	s_observer_globals *observer_globals;
	void *__unknown688;
	void *__unknown690;
	s_first_person_weapons *first_person_weapons;
	void *__unknown6A0;
	s_havok_contact_point_globals *havok_contact_point_globals;
	c_chud_widgets_data_array *chud_widgets_data[4];
	s_usability_globals *usability_globals;
	void *__unknown6D8;
	void *__unknown6E0;
	void *__unknown6E8;
	void *__unknown6F0;
	void *__unknown6F8;
	void *__unknown700;
	void *__unknown708;
	void *__unknown710;
	void *__unknown718;
	void *__unknown720;
	void *__unknown728;
	void *__unknown730;
	void *__unknown738;
	char threading740[12];
	signed __int32 threading74C;
	char threading750[16];
	char thread_name[128];
	void *__unknown7E0;
	void *__unknown7E8;
	void *__unknown7F0;
	void *__unknown7F8;
};

class c_thread_local_storage
{
public:
	static s_thread_local_storage *get();
	static const char *get_thread_name();
};

inline s_thread_local_storage *c_thread_local_storage::get()
{
	intptr_t(&rTlsDirectory)[] = IModuleInterface::Read<intptr_t[]>("HaloReach.dll", 0x180B09CE8);
	int TlsIndex = *reinterpret_cast<int *>(rTlsDirectory[2]);
	s_thread_local_storage *pTls = reinterpret_cast<s_thread_local_storage **>(__readgsqword(0x58u))[TlsIndex];

	if (!pTls->thread_name[0])
		return nullptr;

	return pTls;
}

inline const char *c_thread_local_storage::get_thread_name()
{
	s_thread_local_storage *pTls = get();
	if (!pTls || !pTls->thread_name[0])
		return "`pTls` or `thread_name` is null";

	return pTls->thread_name;
}