#pragma once

enum class Environment
{
    None = 0,
    asteroid,
    sun,
    pulsar,
    PDSPlayer, // PDS target
    PDSEnemy,
    PDSBoth
};

void printEnvironment(Environment hazard);

enum class Fleet
{
    None = 0,
    rebel,
    battle,
    fed
};

enum class AutoRewardType
{
    standard = 0,
    stuff,
    scrap_only,
    fuel,
    missiles,
    droneparts,
    fuel_only,
    missiles_only,
    droneparts_only,
    weapon,
    augment,
    drone
    // TODO something about individual items?
};

struct AutoReward
{
    AutoRewardType type = AutoRewardType::standard;
    Level level = Level::RANDOM;
};

// TODO This might be overcomplicating things
enum class ItemType
{
    scrap = 0,
    fuel,
    missiles,
    drones
};

struct Item
{
    ItemType type = ItemType::scrap;
    int min = 0;
    int max = 0;
};

struct ItemModify
{
    Item scrap;
    Item fuel;
    Item missiles;
    Item drones;
};
