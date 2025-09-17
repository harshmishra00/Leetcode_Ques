import heapq, collections

class FoodRatings(object):

    def __init__(self, foods, cuisines, ratings):
        """
        :type foods: List[str]
        :type cuisines: List[str]
        :type ratings: List[int]
        """
        self.food_info = {f:(r,c) for f,c,r in zip(foods,cuisines,ratings)}
        self.cuisine_heaps = collections.defaultdict(list)
        for f,(r,c) in self.food_info.items():
            heapq.heappush(self.cuisine_heaps[c], (-r, f))

    def changeRating(self, food, newRating):
        """
        :type food: str
        :type newRating: int
        :rtype: None
        """
        _, c = self.food_info[food]
        self.food_info[food] = (newRating, c)
        heapq.heappush(self.cuisine_heaps[c], (-newRating, food))

    def highestRated(self, cuisine):
        """
        :type cuisine: str
        :rtype: str
        """
        heap = self.cuisine_heaps[cuisine]
        while heap:
            neg_r, f = heap[0]
            if -neg_r == self.food_info[f][0]:  # valid
                return f
            heapq.heappop(heap)  # remove outdated
