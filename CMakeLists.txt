cmake_minimum_required(VERSION 3.16.3)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QMarkAutomaton.cpp
        QMarkAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        RightParenthesesAutomaton.cpp
        RightParenthesesAutomaton.h
        MultiAutomaton.cpp
        MultiAutomaton.h
        SchemeAutomaton.cpp
        SchemeAutomaton.h
        IDAutomaton.cpp
        IDAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        UndefinedAutomaton.cpp
        UndefinedAutomaton.h
        DatalogProgram.cpp
        DatalogProgram.h
        Parser.cpp
        Parser.h Parameter.cpp Parameter.h Predicate.cpp Predicate.h Rule.cpp Rule.h Tuple.h Scheme.cpp Scheme.h Database.cpp Database.h Relation.cpp Relation.h Interpreter.cpp Interpreter.h)
