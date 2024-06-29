#pragma once

// Created with ReClass.NET 1.2 by KN4CK3R

// Created with ReClass.NET 1.2 by KN4CK3R

class LocalPlayer
{
public:
	void** PtrTovTable; //0x0000
	Vector3 Position; //0x0004
	Vector3 Velocity; //0x0010
	char pad_001C[24]; //0x001C
	Vector3 Position2; //0x0034
	Vector3 ViewAngles; //0x0040
	char pad_004C[172]; //0x004C
	int32_t PlayerHealth; //0x00F8
	int32_t PlayerArmor; //0x00FC
	char pad_0100[293]; //0x0100
	char Name[16]; //0x0225
	char pad_0235[247]; //0x0235
	int32_t TeamID; //0x032C
	char pad_0330[68]; //0x0330
}; //Size: 0x0374

class EntityList
{
public:
	char pad_0000[320]; //0x0000
}; //Size: 0x0140