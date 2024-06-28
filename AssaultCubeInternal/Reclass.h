#pragma once

// Created with ReClass.NET 1.2 by KN4CK3R
class LocalPlayer
{
public:
	char pad_0000[4]; //0x0000
	Vector3 Position; //0x0004
	Vector3 Velocity; //0x0010
	char pad_001C[24]; //0x001C
	Vector3 Position2; //0x0034
	Vector3 ViewAngles; //0x0040
	char pad_004C[172]; //0x004C
	int32_t PlayerHealth; //0x00F8
	int32_t PlayerArmor; //0x00FC
	char pad_0100[96]; //0x0100
}; //Size: 0x0160