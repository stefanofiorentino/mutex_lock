#include "catch.hpp"
#include "include/run.h"

TEST_CASE( "Solution that leaks", "" )
{
  const std::string consoleInput = "1\n";

  std::istringstream input{consoleInput};

  REQUIRE_THROWS_AS( run(input), std::runtime_error );
}

TEST_CASE( "Solution taht doesn't leak", "" )
{
    const std::string consoleInput = "2\n";

    std::istringstream input{consoleInput};

    REQUIRE_THROWS_AS( run(input), std::runtime_error );
}
