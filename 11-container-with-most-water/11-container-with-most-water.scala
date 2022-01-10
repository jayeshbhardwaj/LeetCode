object Solution {
    def maxArea(height: Array[Int]): Int = {
      val sz = height.size
      if(sz == 0) return 0

      var lmax = 0
      var rmax = sz - 1
      var max = 0
      while(lmax < rmax){
        if(height(lmax) > height(rmax)){
          val water = height(rmax)*(rmax-lmax)
          if(water > max)max = water
          rmax = rmax-1
        } else {
          val water = height(lmax)*(rmax-lmax)
          if(water > max)max = water
          lmax = lmax+1
        }
        
      }
      max
    }
}