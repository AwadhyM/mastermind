class Board {

public:
    Board();
    void renderFirstRow();
private:
    const int boardWidth { 32 }; // TODO - Future work? Pass as arg for more customisability?
    const int feedbackWidth { 8 };
};
