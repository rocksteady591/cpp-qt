#pragma once

#ifdef PRAC_TESTS
#include "../tests/model.h"
#include "../tests/view.h"
#else
#include "model.h"
#include "view.h"
#endif

class Controller {
public:

    Controller() : model_(Model()), view_(View()){
        view_.SetNewgameCallback([&](size_t x, size_t y){
            model_.Reset(x, y);
            view_.SetupField(x, y);
            UpdateGameStatus();
        });
        view_.SetMoveCallback([&](size_t x, size_t y){
            auto result = model_.DoMove(x, y);
            if(result != Symbol::kEmpty){
                view_.UpdateCell(x, y, ToQString(result));
            }
            UpdateGameStatus();
        });

        model_.Reset(3, 3);
        view_.SetupField(3, 3);
        UpdateGameStatus();
        view_.show();
    }


private:
    void UpdateGameStatus(){
        std::optional<Symbol> res = model_.GetWinner();
        if(res == std::nullopt){
            view_.SetStatusStyle("black", false);
            view_.SetStatus("Ход игрока " + ToQString(model_.GetNextPlayer()));
        }else if(res == Symbol::kEmpty){
            view_.SetStatusStyle("red", true);
            view_.SetStatus("Ничья");
        }else{
            view_.SetStatusStyle("green", true);
            auto get_win_cel = model_.GetWinnerPath();
            for(auto& win_cel : get_win_cel){
                view_.SetCellStyle(win_cel.first, win_cel.second, "green", true);
            }
            view_.SetStatus("Выиграл " + ToQString(res.value()));
        }
    }
    Model model_;
    View view_;
};
