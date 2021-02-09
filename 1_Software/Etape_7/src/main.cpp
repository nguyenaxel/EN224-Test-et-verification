#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "pgcd.h"


#define  CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Test PGCD : fonctionnement normal","[pgcd]")
{
	SECTION("A > B")
	{
		REQUIRE(PGCD(128,  32) == 32);
		REQUIRE(PGCD(833, 148) ==  1);
	}
	SECTION("A < B")
	{
		REQUIRE(PGCD(5642, 45468) == 2);
		REQUIRE(PGCD(5642, 45468) == -1);

	}
	SECTION("A = B")
	{
		REQUIRE(PGCD(24, 24) == 24);
	}
	
}

TEST_CASE("Test PGCD : cas particuliers","[pgcd]")
{
	SECTION("A > B")
	{
		REQUIRE(PGCD(48, 0) == 48);
	}
	SECTION("A < B")
	{
		REQUIRE(PGCD(0, 199) == 199);
		REQUIRE(PGCD(0, 199) == 198);
	}
	SECTION("A = B")
	{
		REQUIRE(PGCD(0, 0) == 0);
	}

}
