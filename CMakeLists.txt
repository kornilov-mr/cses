cmake_minimum_required(VERSION 3.26)
project(cses)

set(CMAKE_CXX_STANDARD 17)

add_executable(towers sorting/towers.cpp)
add_executable(traffic sorting/trafficLights.cpp)
add_executable(josephesProblemEasy sorting/josephesProblem1.cpp)
add_executable(NestedRangeCheck sorting/NestedRangeCheck.cpp)
add_executable(josephesProblem sorting/josephesProblem.cpp)
add_executable(NestedRangeCount  sorting/NestedRangeCount.cpp)
add_executable(RoomAllocation  sorting/RoomAllocation.cpp)
add_executable(FactoryMachines  sorting/FactoryMachines.cpp)
add_executable(ReadingBooks  sorting/ReadingBooks.cpp)
add_executable(SumOfThreeValues  sorting/SumOfThreeValues.cpp)
add_executable(TaskAndDeadlines  sorting/TaskAndDeadlines.cpp)
add_executable(NearestSmallerValue  sorting/NearestSmallerValue.cpp)
add_executable(ConcertTicket  sorting/ConcertTicket.cpp)
add_executable(RestaurantCustomers  sorting/RestaurantCustomers.cpp)
add_executable(MovieFestival sorting/MovieFestival.cpp)
add_executable(CollectionNumbers2 sorting/CollectingNumbers2.cpp)
add_executable(SubarraySub sorting/SubarraySum2.cpp)
add_executable(SubarrayDivisibilty sorting/SubarrayDivisibilty.cpp)
add_executable(SubarrayDistinctValues sorting/SubarrayDistinctValues.cpp)
add_executable(SlidingWindowMedian sorting/SlidingWindowMedian.cpp)
add_executable(SlidingWindowCost sorting/SlidingWindowCost.cpp)
add_executable(MovieFestival2 sorting/MovieFestival2.cpp)
add_executable(MaximumSubarraySum2 sorting/MaximumSubarraySum2.cpp)
add_executable(ArrayDivision sorting/arrayDivision.cpp)
add_executable(SumOfFourValue sorting/SumOfFourValue.cpp)

add_executable(PointLocationTest  geometry/PointLocationTest.cpp)
add_executable(LineSegmentIntersection  geometry/LineSegmentIntersection.cpp)
add_executable( PolygonArea  geometry/PolygonArea.cpp)

add_executable(MinimizingCoins DynamicProgramming/MInimizingCoins.cpp)
add_executable(GridPaths DynamicProgramming/GridPaths.cpp)
add_executable(CoinCombination2 DynamicProgramming/CoinCombination2.cpp)
add_executable(CountingTowers DynamicProgramming/CountingTowers.cpp)
add_executable(ArrayDescription DynamicProgramming/ArrayDescription.cpp)
add_executable(MoneySums DynamicProgramming/MoneySums.cpp)
add_executable(BookShop DynamicProgramming/BookShop.cpp)
add_executable(EditDistance DynamicProgramming/EditDistance.cpp)
add_executable(RectangleCutting DynamicProgramming/RectangleCutting.cpp)
add_executable(TwoSets DynamicProgramming/TwoSets2.cpp)
add_executable(IncreasingSubsequence DynamicProgramming/IncreasingSubsequence.cpp)
add_executable(Projects DynamicProgramming/Projects.cpp)
add_executable(Removalgame DynamicProgramming/Removalgame.cpp)
add_executable(ElevatorRides DynamicProgramming/ElevatorRides.cpp)
add_executable(CountingNumbers DynamicProgramming/CountingNumbers.cpp)

add_executable(BuildingRoads Graphs/BuildingRoads.cpp)
add_executable(MessageRoute Graphs/MessageRoute.cpp)
add_executable(ShortestRoutes1 Graphs/ShortestRoutes1.cpp)
add_executable(ShortestRoutes2 Graphs/ShortestRoutes2.cpp)
add_executable(HighScore Graphs/HighScore.cpp)
add_executable(BuildingTeams Graphs/BuildingTeams.cpp)
add_executable(Labyrinth Graphs/Labyrinth.cpp)
add_executable(CycleFinding Graphs/CycleFinding.cpp)
add_executable(RoundTrip Graphs/RoundTrip.cpp)
add_executable(Monsters Graphs/Monsters.cpp)
add_executable(RoundTrip2 Graphs/RoundTrip2.cpp)
add_executable(FlightDiscount Graphs/FlightDiscount.cpp)
add_executable(FlightRoutes Graphs/FlightRoutes.cpp)
add_executable(LongestFlightRoute Graphs/LongestFlightRoute.cpp)
add_executable(CourseSchedule Graphs/FlightRoutes.cpp)
add_executable(GameRoutes Graphs/GameRoutes.cpp)
add_executable(RoadReparation Graphs/RoadReparation.cpp)
add_executable(RoadConstruct Graphs/RoadConstruction.cpp)

add_executable(StaticRangeSumQueries RangeQueries/StaticRangeSumQueries.cpp)
add_executable(StaticRangeMinimumQueries RangeQueries/StaticRangeMinimumQueries.cpp)

