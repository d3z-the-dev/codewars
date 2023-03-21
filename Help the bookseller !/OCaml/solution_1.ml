let stock_list (lart: string array) (lcat: string array) =
    if Array.length lart = 0 || Array.length lcat = 0 then ""
    else
        let quantities = Array.make (Char.code 'Z' + 1) 0 in
        Array.iter (fun book ->
            let position = String.index_from book 2 ' ' in
            quantities.(Char.code book.[0]) <- quantities.(Char.code book.[0]) + int_of_string 
            (String.sub book (position + 1) (String.length book - position - 1))
        ) lart;
        let result = ref "" in
        Array.iter (fun category ->
            result := !result ^ (if !result = "" then "" else " - ") ^ 
            "(" ^ String.make 1 category.[0] ^ " : " ^ string_of_int quantities.(Char.code category.[0]) ^ ")"
        ) lcat;
    !result;;