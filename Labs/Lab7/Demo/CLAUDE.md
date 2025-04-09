# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

我正在完成这个Lab文件，我所需要完成的文件是Lab7_2script，Lab7_1script是一个示例文件，在同一目录下，有一个用于储存演员-电影1 电影2....的电影库文件，
它直接作用在Lab7_2script上，我所需要完成的部分在#————————————————————————...之后，约在60行左右开始。

你需要协助我完成这项文件，对于文件的需求已经大致地包含在了文件内，你可以结合以下信息和文件内容查看：
1：这个脚本主要分析两部电影中的演员阵容，用集合来展示不同演员信息
	脚本接受一个命令行参数：actor_movies.txt文件的路径
2：提示用户输入两部电影的标题
3：验证这两部电影是否存在在数据库中
4：如果两部电影有效，反复显示菜单直到用户手动选择退出(输入Q或q)

以下是已经完成的代码的输出示例，我们要完成的结果要尽可能等同于这个输出的结果：
$ ./Lab7_2script actor_movies.txt
Please input the first movie title:
CS216↵
Please input the second movie title:
Die Hard↵
Invalid movie title.
The following shows another sample output:
$ ./Lab7_2script actor_movies.txt
Please input the first movie title:
got Mail↵
Please input the second movie title:
catch mE↵
Your input matches these two movies:
You've Got Mail (1998)
Catch Me If You Can (2002)
Both movies are in the database, please continue...
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
c↵
Common actors in both movies:
Tom Hanks
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
a↵
All the actors in either of the two movies:
Christopher Walken
Greg Kinnear
Leonardo DiCaprio
Martin Sheen
Meg Ryan
Parker Posey
Tom Hanks
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
o↵
Actors only in one of two movies:
Christopher Walken
Greg Kinnear
Leonardo DiCaprio
Martin Sheen
Meg Ryan
Parker Posey
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
Q↵
Delete all temporary files...
The following shows another sample output:
Please input the first movie title:
School of ROck↵
Please input the second movie title:
High fideLITY↵
Your input matches these two movies:
School of Rock (2003)
High Fidelity (2000)
Both movies are in the database, please continue...
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
k↵
Invalid option.
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
P↵
Invalid option.
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
O↵
Actors only in one of two movies:
Iben Hjejle
Joan Cusack
John Cusack
Mike White
Sarah Silverman
Todd Louiso
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
C↵
Common actors in both movies:
Jack Black
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
A↵
All the actors in either of the two movies:
Iben Hjejle
Jack Black
Joan Cusack
John Cusack
Mike White
Sarah Silverman
Todd Louiso
Please input your menu option (enter Q or q to quit)
A --to print all the actors in either of the two movies.
C --to print all the common actors in both of the movies.
O --to print all the actors who are in one movie, but not in
both.
q↵
Delete all temporary files...

