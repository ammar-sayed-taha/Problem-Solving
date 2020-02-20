#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define umapii map<int, int>
#define umapivi map<int, vi>
#define umapivvi map<int, vvi>

// convert views from vector to map to reduce loop operations later
umapivvi convertViewsToMap(vvi &views){
    umapivvi newViews;
    for(auto view: views){
        newViews[view[0]].push_back({view[1], view[2]});
    }
    return newViews;
}
// convert topicIds from vector to map to reduce loop operations later
umapivi convertTopicIdsToMap(vvi &topicIds){
    umapivi newTopicsIds;
    int topicLen = topicIds.size();
    for(int i=0; i<topicLen; i++)
        for(int id: topicIds[i])
            newTopicsIds[id].push_back(i);
    return newTopicsIds;
}

// get the most views writers
vvi getViews(umapivvi &views, vi &tempAnsIds){
    vvi result;
    umapii userIdViews;

    for(int id: tempAnsIds){
        vvi view = views[id];
        for(vi v:view){
            if(userIdViews.find(v[0]) != userIdViews.end())
                userIdViews[v[0]] += v[1];
            else
                userIdViews[v[0]] = v[1];
        }
    }
    // set result data in result variable
    for(auto user: userIdViews){
        result.push_back({user.first, user.second});
    }
    return result;
}

bool viewsComp(vi x, vi y){
    if(y[1] > x[1])
        return false;
    if(y[1] == x[1] && y[0] < x[0])
        return false;
    return true;
}

std::vector<std::vector<std::vector<int>>> mostViewedWriters(std::vector<std::vector<int>> topicIds,
        std::vector<std::vector<int>> answerIds, std::vector<std::vector<int>> views) {

    vvvi result;
    umapivi newTopicsIds;
    umapivvi newViews;
    vi tempAnsIds;

    // loop over topicIds and collect ids in map
    newTopicsIds = convertTopicIdsToMap(topicIds);

    // get new views shape
    newViews = convertViewsToMap(views);

    // loop over each topicId and calculate views
    for(auto &ansIds: newTopicsIds){
        tempAnsIds.clear();
        for(int idx : ansIds.second){
            // loop over answers and get inswer ids
            for(int i=0; i<answerIds[idx].size(); i++)
                tempAnsIds.push_back(answerIds[idx][i]);
        }
        result.push_back(getViews(newViews, tempAnsIds));
    }

    int resLen = result.size();
    for(int i=0; i<resLen; i++)
        sort(result[i].begin(), result[i].end(), viewsComp);

    return result;
}
