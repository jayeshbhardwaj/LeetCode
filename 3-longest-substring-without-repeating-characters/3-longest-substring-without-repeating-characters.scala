import scala.collection.mutable.HashMap
object Solution {
    def lengthOfLongestSubstring(s: String): Int = {
        if(s.size == 0) return 0
        var max = 1
        var start = 0
        var chars:HashMap[Char,Int] = HashMap[Char,Int]()
        var st = 0
        var end = 0
        var count = 0
       var res = 0
        while(end < s.size){
          chars.put(s(end),chars.getOrElse(s(end),0)+1)
          if(chars(s(end)) > 1){
            count = 1
          }
          end = end + 1
          while(count == 1){
            chars.put(s(st),chars(s(st))-1)
            if(chars(s(st)) == 1){
              count = count - 1
            }
            st = st + 1 
          }
          res = res max (end - st)
          
        }
      res
        
    }
}