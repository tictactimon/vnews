<?php

class rex_vnews_news_category {

  static $users = array();
  private $user = array();

  // ----------------

  static function getTable()
  {
    return 'vnews_category';
  }

  function __construct($user) {
    $this->user = $user;
  }






  static function triggerUserCreated($id, $params = array())
  {

    rex_register_extension_point("vnews_USER_CREATED", $id, $params, true); // read only

  }

  static function triggerUserUpdated($id, $params = array())
  {


    rex_register_extension_point("vnews_USER_UPDATED", $id, $params, true); // read only

  }


}

