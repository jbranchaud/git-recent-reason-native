let apply_color_by_index = (index, str) =>
  switch (index) {
  | 0
  | 1 => Color.red(str)
  | 2
  | 3 => Color.green(str)
  | 4
  | 5 => Color.yellow(str)
  | 6
  | 7 => Color.blue(str)
  | 8
  | 9 => Color.magenta(str)
  | _ => str
  };

/* source: https://stackoverflow.com/a/5972362/535590 */
let command = "git for-each-ref --count=10 --sort=-committerdate refs/heads/ --format='%(refname:short)'";

/* open a process executing the 'pwd' command */
let process_in_channel = Unix.open_process_in(command);

/* create a stream of the list of branches, applying color */
let branch_stream =
  Stream.from(i =>
    switch (input_line(process_in_channel)) {
    | line => Some(apply_color_by_index(i, line))
    | exception End_of_file => None
    }
  );

/* iterate over the stream, printing each out */
branch_stream |> Stream.iter(branch => print_endline(branch));

/* cleanup by closing input channel */
Unix.close_process_in(process_in_channel);