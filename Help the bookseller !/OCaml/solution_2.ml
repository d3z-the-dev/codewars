let stock_list (lart : string array) (lcat : string array) =
    if Array.length lart = 0 then ""
    else 
        let qs c = "("^c^" : " ^ string_of_int (Array.fold_left (fun i o  ->
            if o.[0] = c.[0]
            then i + ( Str.split (Str.regexp " ") o |> List.tl |> List.hd |> int_of_string  )
            else i ) 0 lart)^")"
        in Array.fold_left (fun i o -> 
            match i with |"" -> qs o |_ -> i ^ " - " ^ qs o )  ""  lcat