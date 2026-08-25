//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef enchantments_h
#define enchantments_h

protected string *enchantmentClasses = ({ "offensive", "defensive", "vitals", 
    "attributes", "skills", "abilities", "attack mutations" });

protected mapping equipmentEnchantments =
([
    "fire enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental fire": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "fire": 2,
            ]),
        ]),
        "rune": "kenaz",
        "description": "Imbues the item with fiery energy, enhancing damage with searing heat.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "fire resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental fire": (["type": "skill", "value": 5]),
        ]),
        "defense": ([
            "fire": 2,
        ]),
        "effects": ([
            "resistances": ([
                "fire": 2,
            ]),
        ]),
        "rune": "kenaz",
        "description": "Protects the wearer against heat and fire damage through magical warding.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "fire attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/fire/craftFireAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "elemental fire": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "fire",
        ]),
        "rune": "kenaz",
        "description": "Converts the weapon's attacks to channel burning fire element energy.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "acid enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/acid/craftAcidEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "destruction": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "acid":2,
            ]),
        ]),
        "rune": "hagalaz",
        "description": "Enhances the item with corrosive energy that eats through defenses.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "acid resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/acid/craftAcidEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "destruction": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "acid":2,
            ]),
        ]),
        "rune": "hagalaz",
        "description": "Provides magical protection against corrosive substances and acid damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "acid attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/acid/craftAcidAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "destruction": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "acid",
        ]),
        "rune": "hagalaz",
        "description": "Transforms weapon strikes to deliver devastating acid damage on contact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "air enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/air/craftAirEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental air": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "air":2,
            ]),
        ]),
        "rune": "tiwaz",
        "description": "Infuses the item with swift air energy, increasing its effectiveness.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "air resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/air/craftAirEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental air": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "air":2,
            ]),
        ]),
        "rune": "tiwaz",
        "description": "Creates a magical barrier that deflects air-based attacks and damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "air attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/air/craftAirAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "elemental air": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "air",
        ]),
        "rune": "tiwaz",
        "description": "Imbues weapon strikes with cutting air currents for enhanced damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "chaos enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/chaos/craftChaosEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "transformation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "chaos":2,
            ]),
        ]),
        "rune": "perthro",
        "description": "Empowers the item with unpredictable chaos magic that warps reality.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "chaos resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/chaos/craftChaosEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "transformation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "chaos":2,
            ]),
        ]),
        "rune": "perthro",
        "description": "Stabilizes reality around the wearer, protecting against chaotic energies.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "chaos attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/chaos/craftChaosAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "transformation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "chaos",
        ]),
        "rune": "perthro",
        "description": "Converts weapon damage to unpredictable chaos energy that distorts matter.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "cold enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/cold/craftColdEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "cold":2,
            ]),
        ]),
        "rune": "isa",
        "description": "Imbues the item with freezing energy that chills opponents to the bone.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "cold resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/cold/craftColdEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "cold":2,
            ]),
        ]),
        "rune": "isa",
        "description": "Creates an insulating magical field that protects against cold damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "cold attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/cold/craftColdAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "cold",
        ]),
        "rune": "isa",
        "description": "Transforms weapon strikes to deliver biting cold damage that slows targets.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "disease enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/disease/craftDiseaseEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "disease":2,
            ]),
        ]),
        "rune": "kenaz merkstave",
        "description": "Curses the item to spread virulent disease and decay to enemies.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "disease resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/disease/craftDiseaseEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "disease":2,
            ]),
        ]),
        "rune": "kenaz merkstave",
        "description": "Strengthens the wearer's vitality against disease and illness.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "earth enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/earth/craftEarthEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental earth": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "earth":2,
            ]),
        ]),
        "rune": "ingwaz",
        "description": "Empowers the item with crushing earth energy for enhanced impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "earth resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/earth/craftEarthEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental earth": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "earth":2,
            ]),
        ]),
        "rune": "ingwaz",
        "description": "Creates a barrier of magical earth energy that absorbs physical blows.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "earth attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/earth/craftEarthAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "elemental earth": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "fire",
        ]),
        "rune": "ingwaz",
        "description": "Transforms weapon strikes to deliver crushing earth energy on impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "electricity enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/electricity/craftElectricityEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental air": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "electricity":2,
            ]),
        ]),
        "rune": "ansuz",
        "description": "Charges the item with crackling lightning energy that shocks opponents.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "electricity resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/electricity/craftElectricityEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental air": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "electricity":2,
            ]),
        ]),
        "rune": "ansuz",
        "description": "Grounds electrical energy, protecting the wearer from lightning damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "electricity attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/electricity/craftElectricityAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "elemental air": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "electricity",
        ]),
        "rune": "ansuz",
        "description": "Transforms weapon strikes to deliver shocking electrical damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "energy enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/energy/craftEnergyEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "evocation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "energy":2,
            ]),
        ]),
        "rune": "fehu",
        "description": "Infuses the item with pure magical energy that enhances its power.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "energy resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/energy/craftEnergyEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "evocation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "energy":2,
            ]),
        ]),
        "rune": "fehu",
        "description": "Creates a barrier that dissipates energy attacks before they reach the wearer.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "energy attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/energy/craftEnergyAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "evocation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "energy",
        ]),
        "rune": "fehu",
        "description": "Transforms weapon strikes to release pure magical energy on impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "evil enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/evil/craftEvilEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "blood": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "evil":2,
            ]),
        ]),
        "rune": "thurisaz merkstave",
        "description": "Fills the item with dark, corrupting energy that saps life and will.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "evil resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/good/craftGoodEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "spirit": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "evil":2,
            ]),
        ]),
        "rune": "uruz",
        "description": "Shields the wearer's spirit from corruption and dark energies.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "evil attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/evil/craftEvilAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "blood": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "evil",
        ]),
        "rune": "thurisaz merkstave",
        "description": "Transforms weapon strikes to deliver soul-corrupting dark energy.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "good enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/good/craftGoodEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "spirit": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "good":2,
            ]),
        ]),
        "rune": "uruz",
        "description": "Blesses the item with radiant energy that smites evil and darkness.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "good resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/evil/craftEvilEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "blood": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "good":2,
            ]),
        ]),
        "rune": "thurisaz merkstave",
        "description": "Cloaks the wearer in shadows that deflect holy and radiant energies.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "good attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/good/craftGoodAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "spirit": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "good",
        ]),
        "rune": "uruz",
        "description": "Transforms weapon strikes to channel purifying holy energy.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "magical enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/magical/craftMagicalEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "magical essence": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "magical":2,
            ]),
        ]),
        "rune": "gebo",
        "description": "Enhances the item with arcane power that bypasses mundane defenses.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "magical resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/magical/craftMagicalEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "magical essence": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "magical":2,
            ]),
        ]),
        "rune": "gebo",
        "description": "Weaves a counter-spell barrier that neutralizes harmful magic.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "magical attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/magical/craftMagicalAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "magical essence": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "magical",
        ]),
        "rune": "gebo",
        "description": "Transforms weapon strikes to unleash pure arcane energy that penetrates defenses.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "neutral enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/neutral/craftNeutralEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "magical essence": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "neutral":2,
            ]),
        ]),
        "rune": "raidho",
        "description": "Balances the item with neutral energy that bypasses alignment defenses.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "neutral resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/neutral/craftNeutralEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "magical essence": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "neutral":2,
            ]),
        ]),
        "rune": "raidho",
        "description": "Creates a barrier of balanced energy that protects against neutral forces.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "neutral attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/neutral/craftNeutralAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "magical essence": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "neutral",
        ]),
        "rune": "raidho",
        "description": "Transforms weapon strikes to balanced neutral energy that affects all beings equally.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "paralysis enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/paralysis/craftParalysisEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "paralysis":2,
            ]),
        ]),
        "rune": "nauthiz",
        "description": "Enchants the item to emit energy that restricts movement and mobility.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "paralysis resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/paralysis/craftParalysisEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "paralysis":2,
            ]),
        ]),
        "rune": "nauthiz",
        "description": "Reinforces the wearer's nervous system against paralytic effects.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "poison enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/poison/craftPoisonEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "transformation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "poison":2,
            ]),
        ]),
        "rune": "algiz merkstave",
        "description": "Imbues the item with toxic energies that sicken and weaken foes over time.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "poison resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/poison/craftPoisonEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "transformation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "poison":2,
            ]),
        ]),
        "rune": "algiz",
        "description": "Neutralizes poisons and venoms before they can harm the wearer.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "psionic enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/psionic/craftPsionicEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "mind": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                 "psionic":2,
            ]),
        ]),
        "rune": "wunjo",
        "description": "Attunes the item to mental energies that disrupt thought and concentration.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "psionic resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/psionic/craftPsionicEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "mind": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "psionic":2,
            ]),
        ]),
        "rune": "wunjo",
        "description": "Shields the wearer's mind against psychic attacks and mental intrusion.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "psionic attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/psionic/craftPsionicAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "mind": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "psionic",
        ]),
        "rune": "wunjo",
        "description": "Transforms weapon strikes to deliver mind-searing psychic energy.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "sonic enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/sonic/craftSonicEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "senses": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                 "sonic":2,
            ]),
        ]),
        "rune": "sowilo",
        "description": "Charges the item with vibration energy that creates damaging sound waves.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "sonic resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/sonic/craftSonicEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "senses": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "sonic":2,
            ]),
        ]),
        "rune": "sowilo",
        "description": "Dampens harmful sound waves before they can damage the wearer.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "sonic attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/sonic/craftSonicAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "senses": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "sonic",
        ]),
        "rune": "sowilo",
        "description": "Transforms weapon strikes to release devastating sonic vibrations on impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "undead enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/undead/craftUndeadEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "destruction": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "undead":2,
            ]),
        ]),
        "rune": "berkano merkstave",
        "description": "Infuses the item with negative energy that disrupts the essence of life.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "undead resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/undead/craftUndeadEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "destruction": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "undead":2,
            ]),
        ]),
        "rune": "berkano merkstave",
        "description": "Reinforces life energy to protect against draining undead attacks.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "undead attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/undead/craftUndeadAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "blood": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "undead",
        ]),
        "rune": "berkano merkstave",
        "description": "Transforms weapon strikes to unleash life-draining negative energy.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "water enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/water/craftWaterEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "water":2,
            ]),
        ]),
        "rune": "laguz",
        "description": "Imbues the item with flowing water energy that erodes defenses over time.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "water resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/water/craftWaterEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "water":2,
            ]),
        ]),
        "rune": "laguz",
        "description": "Creates a magical barrier that repels and diverts water damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "water attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/water/craftWaterAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "water",
        ]),
        "rune": "laguz",
        "description": "Transforms weapon strikes to deliver crushing water energy on impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "weapon damage":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "transformation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "bonus damage": 2,
        ]),
        "rune": "eihwaz",
        "description": "Sharpens and reinforces the weapon's edge, increasing its damage potential.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "weapon attack":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "evocation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "bonus attack": 2,
        ]),
        "rune": "jera",
        "description": "Guides the weapon toward vital targets, increasing accuracy and attack effectiveness.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "additional attack":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "evocation": (["type": "skill", "value": 10]),
        ]),
        "effects": ([
            "bonus weapon attack": 1,
        ]),
        "rune": "eihwaz",
        "description": "Accelerates the wielder's movements, allowing an additional strike in combat.",
        "value multiplier": 10.0,
        "experience modifier": 1.6
    ]),
    "weapon defense":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftWeaponEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "manipulation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "bonus defense class":2,
        ]),
        "rune": "algiz",
        "description": "Enhances the weapon's ability to parry and deflect incoming attacks.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "damage soak": ([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/protection/craftSoakEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "bonus soak": 2,
        ]),
        "rune": "algiz",
        "description": "Creates a magical barrier that absorbs and dissipates incoming damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "damage reflection":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/weapon/craftDamageReflection.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "apply damage reflection": 15,
        ]),
        "rune": "othala",
        "description": "Rebounds a portion of received damage back to the attacker.",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "hit points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftHitPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "bonus hit points":5,
        ]),
        "rune": "berkano",
        "description": "Bolsters the wearer's life force, increasing maximum health.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal hit points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftHitPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "body": (["type": "skill", "value": 10]),
        ]),
        "effects": ([
            "bonus heal hit points":1,
        ]),
        "rune": "berkano",
        "description": "Enhances the wearer's natural healing, restoring more health when recovering.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal hit points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftHitPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "body": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus heal hit points rate":1,
        ]),
        "rune": "berkano",
        "description": "Accelerates the body's natural healing process, recovering health more quickly.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "stamina points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftStaminaPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "body": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "bonus hit points":5,
        ]),
        "rune": "ehwaz",
        "description": "Enhances the wearer's endurance, increasing maximum stamina reserves.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal stamina points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftStaminaPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "body": (["type": "skill", "value": 10]),
        ]),
        "effects": ([
            "bonus heal stamina points":1,
        ]),
        "rune": "ehwaz",
        "description": "Enhances the body's recovery, restoring more stamina when resting.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal stamina points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftStaminaPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "body": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus heal stamina points rate":1,
        ]),
        "rune": "ehwaz",
        "description": "Accelerates stamina recovery, allowing the wearer to regain energy more quickly.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "spell points":([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftSpellPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "magical essence": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "bonus spell points":5,
        ]),
        "rune": "dagaz",
        "description": "Expands the wearer's magical capacity, increasing maximum spell points.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal spell points amount": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftSpellPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "magical essence": (["type": "skill", "value": 10]),
        ]),
        "effects": ([
            "bonus heal spell points":1,
        ]),
        "rune": "dagaz",
        "description": "Enhances magical recovery, restoring more spell points when meditating.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "heal spell points rate": ([
        "class": "vitals",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/vitals/craftSpellPointsEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "magical essence": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus heal spell points rate":1,
        ]),
        "rune": "dagaz",
        "description": "Accelerates magical energy recovery, regaining spell points more quickly.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "enhance strength":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftStrengthEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "body": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus strength":1,
        ]),
        "rune": "stregaz",
        "description": "Magically enhances the wearer's physical strength beyond natural limits.",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance intelligence":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftIntelligenceEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "mind": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus intelligence":1,
        ]),
        "rune": "inigaz",
        "description": "Magically sharpens the wearer's intellect and reasoning abilities.",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance wisdom":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftWisdomEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "senses": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus wisdom":1,
        ]),
        "rune": "wesgaz",
        "description": "Magically enhances the wearer's insight, intuition and perception.",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance dexterity":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftDexterityEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "manipulation": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus dexterity":1,
        ]),
        "rune": "dezgano",
        "description": "Magically enhances the wearer's agility, reflexes and coordination.",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance constitution":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftConstitutionEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "body": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus constitution": 1,
        ]),
        "rune": "corgaz",
        "description": "Magically enhances the wearer's physical resilience and fortitude.",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "enhance charisma":([
        "class": "attributes",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/attributes/craftCharismaEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "mind": (["type": "skill", "value": 15]),
        ]),
        "effects": ([
            "bonus charisma": 1,
        ]),
        "rune": "sylgaz",
        "description": "Magically enhances the wearer's presence, charm and social influence.",
        "value multiplier": 8.0,
        "experience modifier": 1.55
    ]),
    "steam enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/steam/craftSteamEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "steam": 2,
            ]),
        ]),
        "rune": "laguz kenaz",
        "description": "Imbues the item with scalding steam energy, enhancing damage with searing heat and moisture.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "steam resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/steam/craftSteamEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "steam": 2,
            ]),
        ]),
        "rune": "laguz kenaz",
        "description": "Protects the wearer against scalding steam and superheated vapor damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "steam attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/steam/craftSteamAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "elemental water": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "steam",
        ]),
        "rune": "laguz kenaz",
        "description": "Converts the weapon's attacks to release scalding steam on impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "shadow enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/shadow/craftShadowEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "spirit": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "shadow": 2,
            ]),
        ]),
        "rune": "thurisaz",
        "description": "Imbues the item with void-shadow energy drawn from the spaces between light.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "shadow resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/shadow/craftShadowEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "spirit": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "shadow": 2,
            ]),
        ]),
        "rune": "thurisaz",
        "description": "Wards the wearer against shadow and void energy damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "shadow attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/shadow/craftShadowAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "spirit": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "shadow",
        ]),
        "rune": "thurisaz",
        "description": "Converts the weapon's attacks to channel void-shadow energy on impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "radiant enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/radiant/craftRadiantEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "theology": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "radiant": 2,
            ]),
        ]),
        "rune": "sowilo",
        "description": "Blesses the item with radiant divine light that burns through darkness.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "radiant resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/radiant/craftRadiantEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "theology": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "radiant": 2,
            ]),
        ]),
        "rune": "sowilo",
        "description": "Suffuses the item with holy light that deflects radiant and divine damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "radiant attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/radiant/craftRadiantAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "theology": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "radiant",
        ]),
        "rune": "sowilo",
        "description": "Converts the weapon's attacks to channel searing radiant divine energy.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "temporal enchantment":([
        "class": "offensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/temporal/craftTemporalEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "evocation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "enchantments": ([
                "temporal": 2,
            ]),
        ]),
        "rune": "jera",
        "description": "Infuses the item with temporal energy that disrupts the flow of time on impact.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "temporal resistance":([
        "class": "defensive",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/temporal/craftTemporalEnchantment.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 5]),
            "evocation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "resistances": ([
                "temporal": 2,
            ]),
        ]),
        "rune": "jera",
        "description": "Anchors the wearer in time, protecting against temporal distortion damage.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
    "temporal attack":([
        "class": "attack mutations",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/enchantments/temporal/craftTemporalAttack.lpc":(["type": "research"]),
            "spellcraft": (["type": "skill", "value": 10]),
            "evocation": (["type": "skill", "value": 5]),
        ]),
        "effects": ([
            "damage type": "temporal",
        ]),
        "rune": "jera",
        "description": "Converts the weapon's attacks to unleash temporal distortion energy.",
        "value multiplier": 5.0,
        "experience modifier": 1.5
    ]),
]);

#endif
