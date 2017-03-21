<?php

class rex_vnews_news_author {

  static $users = array();
  private $user = array();

  // ----------------

  static function getTable()
  {
    return 'vnews_author';
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

