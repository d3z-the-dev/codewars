let find_multiples integer limit =
    List.init (limit / integer) (fun x -> (x + 1) * integer) ;;