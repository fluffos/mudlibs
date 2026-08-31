string query_alignment_title(int al) {
  switch (al) {
    case 1500..5000:   return "godly";
    case 1001..1499:   return "saintly";
    case 751..1000:    return "righteous";
    case 501..750:     return "good";
    case 281..500:     return "benevolent";
    case 136..280:     return "nice";

    default:
    case -134..135:    return "neutral";

    case -299..-135:   return "mean";
    case -499..-300:   return "malevolent";
    case -799..-500:   return "bad";
    case -1099..-800:  return "evil";
    case -1499..-1100: return "demonic";
    case -5000..-1500: return "satanic";
  }

  return "neutral";
}

