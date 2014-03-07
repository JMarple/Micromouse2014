//Functions to get and store info from and to integer data cells

//Notes:
// - What I find online says this implementation of C uses a logical bitshift, not an arithmetic. If it is arithmetic, then some things will need changing. If it doesn't work, this is probably why.
// - All inputs that can be call-by-value currently are. I'm not sure whether by-value or by-reference is better for efficiency, so feel free to change everything to call-by-reference if that is appropriate.

//My general procedures, for debugging:
//Get:
//	Bit-shift left to wipe out all digits to the left of the desired value.
//	Bit-shift right to wipe out values to the right and get the relevant value to the one's place.
//Set:
//	Bit-shift right to wipe out the digit and things to its right.
//	Bit-shift left to get 0s where value will go in last place(s)
//	Add value desired to be set to
//	Bit-shift left to get to correct positions
//	Add remaining digits back, obtained by:
//		Bit-shift left to wipe out digits already possessed
//		Bit-shift right to get to original positions

//Example (Suppose: find/set value B from ABCD)
//Get:
//	ABCD<<1 -> BCD0
//	BCD0>>3 -> 000B
//Set (to E):
//	ABCD>>3 -> 000A
//	000A<<1 -> 00A0
//	00A0+E -> 00AE
//	00AE<<2 -> AE00
//	AE00+00CD=AECD
//		ABCD<<2 -> CD00
//		CD00>>2 -> 00CD

//Data storage Mechanism: -XXXXXXXXDDINSEW
//-: Extra bit
//X: Digit of distance
//DD: Direction departed
//I: Is explored
//NSEW: North, South, East, West


//Getting components
int getN(int input)
{
	return ((input<<12)>>15);
}
int getE(int input)
{
	return ((input<<13)>>15);
}
int getS(int input)
{
	return ((input<<14)>>15);
}
int getW(int input)
{
	return ((input<<15)>>15);
}
int getExp(int input)
{
	return ((input<<11)>>15);
}
int getExitDir(int input)
{
	return ((input<<9)>>14);
}
int getDist(int input)
{
	return input>>7;
}

//Setting components: var=variable to change, val=value to give
void setN(int& var, int val)
{
	var=((((var>>4)<<1)+val)<<3)+((var<<13)>>13)
}
void setE(int& var, int val)
{
	var=((((var>>3)<<1)+val)<<2)+((var<<14)>>14)
}
void setS(int& var, int val)
{
	var=((((var>>2)<<1)+val)<<1)+((var<<15)>>15)
}
void setW(int& var, int val)
{
	var=((var>>1)<<1)+val
}
void setExp(int& var, int val)
{
	var=((((var>>5)<<1)+val)<<4)+((var<<12)>>12)
}
void setExitDir(int& var, int val)
{
	var=((((var>>7)<<2)+val)<<5)+((var<<11)>>11)
}
void setDistance(int& var, int val)
{
	var=(val<<7)+((var<<9)>>9)
}
