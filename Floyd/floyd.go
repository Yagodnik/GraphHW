package main
import (
  "fmt"
  "math"
)

func PrepareGraph(graph *[][]int) {
  if graph == nil {
    return
  }
  
  v_count := len(*graph)
  for i := 0; i < v_count;i++ {
    for j := 0; j < v_count;j++ {
      if (*graph)[i][j] == 0 && (i != j) {
        (*graph)[i][j] = math.MaxInt
      }
    } 
  }
}

func FloydAlgorithm(graph [][]int, distances *[][]int) {
  if distances == nil {
    return
  }
  
  v_count := len(graph)
  for i := 0; i < v_count;i++ {
    for j := 0; j < v_count;j++ {
      (*distances)[i][j] = graph[i][j]
    } 
  }

  distance_ji, distance_ik, distance_jk := 0, 0, 0
  for i := 0; i < v_count;i++ {
    for j := 0; j < v_count;j++ {
      for k := 0; k < v_count;k++ {
        distance_ji = (*distances)[j][i]
        distance_ik = (*distances)[i][k]
        distance_jk = (*distances)[j][k]

        if distance_ji + distance_ik < distance_jk && 
          distance_ji != math.MaxInt && 
          distance_ik != math.MaxInt {
          (*distances)[j][k] = distance_ji + distance_ik
        }
      }  
    }
  }
}

func main() {
  graph := [][]int{
    []int{0, 2, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{2, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{4, 3, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{1, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{0, 1, 2, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{0, 0, 2, 5, 0, 0, 3, 3, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{0, 0, 0, 4, 0, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 0, 0, 0 },
    []int{0, 0, 0, 0, 0, 2, 0, 0, 0, 3, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
    []int{0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 6, 0, 6, 3, 0, 0, 0, 0, 0, 0, 0 },
    []int{0, 0, 0, 0, 0, 0, 2, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 3, 0, 6, 0, 0, 0, 0, 0, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 2, 6, 0, 3, 0, 5, 4, 2, 0, 0, 0, 0, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 5, 0, 0, 0, 2, 1, 0, 0, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6, 4, 0, 0, 2, 0, 0, 6, 0, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 1, 0, 2, 1, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 8, 0, 3, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 8, 0, 0, 5, 0 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 0, 0, 2 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 5, 0, 0, 8 },
    []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0 },
  }
  
  PrepareGraph(&graph)
  
  v_count := len(graph)
  distances := make([][]int, v_count)
  for i := 0;i < v_count;i++ {
    distances[i] = make([]int, v_count)
  }
  
  FloydAlgorithm(graph, &distances)
  
  fmt.Println("Floyd algorithm output:")
  
  for i := 0; i < v_count;i++ {
    for j := 0; j < v_count;j++ {
      fmt.Print(distances[i][j], " ")
    } 
    fmt.Println()
  }
}